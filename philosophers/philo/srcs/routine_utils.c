/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:52:17 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/10 14:34:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_ph_eat(t_philo *philo);
static int	_ph_is_eating(t_philo *philo, long long eat_start);
static int	_ph_sleep(t_philo *philo);
static int	_ph_think(t_philo *philo);

void	*start_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	philo->last_eat = current_time();
	if (philo->eat_cnt == 0 && philo->id % 2 == 0)
		usleep(100);	// die_t 고려해서 다시 시간 정할 것
	while (TRUE)
	{
		if (_ph_eat(philo) == END || philo->full == TRUE)
			return (NULL);
		if (_ph_sleep(philo) == END)
			return (NULL);
		if (_ph_think(philo) == END)
			return (NULL);
	}
	// return (NULL);
}

static int	_ph_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->f_state[philo->left]);
	print_message(philo, FORK);
	philo->data->forks[philo->left] = TRUE;
	pthread_mutex_lock(&philo->data->f_state[philo->right]);
	print_message(philo, FORK);
	philo->data->forks[philo->right] = TRUE;

	if (_ph_is_eating(philo, current_time()) == END)
		return (END);

	philo->data->forks[philo->left] = FALSE;
	pthread_mutex_unlock(&philo->data->f_state[philo->left]);
	philo->data->forks[philo->right] = FALSE;
	pthread_mutex_unlock(&philo->data->f_state[philo->right]);
	return (CONTINUE);
}

static int	_ph_is_eating(t_philo *philo, long long eat_start)
{
	print_message(philo, EAT);		// 위치 다시 고려할 것
	while (current_time() - eat_start < philo->data->eat_t)
	{
		if (check_dead(philo->data) == TRUE)
		{
			philo->data->forks[philo->left] = FALSE;
			pthread_mutex_unlock(&philo->data->f_state[philo->left]);
			philo->data->forks[philo->right] = FALSE;
			pthread_mutex_unlock(&philo->data->f_state[philo->right]);
			return (END);	// return 값이 없어서 그냥 종료하고 monitoring에서 잡힐 것이라 예상중 ^^ >> 응 잡아써~
		}
	}
	if (++(philo->eat_cnt) == philo->data->must_eat)
		philo->full = TRUE;
	philo->last_eat = current_time();
	return (CONTINUE);
}

static int	_ph_sleep(t_philo *philo)
{
	print_message(philo, SLEEP);	// 위치 다시 고려
	while (current_time() - philo->last_eat < philo->data->sleep_t)
		if (check_dead(philo->data) == TRUE)
			return (END);
	return (CONTINUE);
}

static int	_ph_think(t_philo *philo)
{
	print_message(philo, THINK);	// 위치 다시 고려
	if (check_dead(philo->data == TRUE))
		return (END);
	return (CONTINUE);
}
