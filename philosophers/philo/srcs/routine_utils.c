/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:52:17 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/11 20:30:18 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_ph_eat(t_philo *philo, t_data *data);
static int	_ph_pick_fork(t_philo *philo, t_data *data);
static int	_ph_is_eating(t_philo *philo, t_data *data, long long eat_start);
static int	_ph_sleep_and_think(t_philo *philo, t_data *data);

void	*start_routine(void *ph)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ph;
	data = philo->data;
	philo->last_eat = current_time();
	if (philo->eat_cnt == 0 && philo->id % 2 == 0)
		usleep(500);	// die_t 고려해서 다시 시간 정할 것
	while (someone_dead(data) == FALSE)
	{
		if (_ph_eat(philo, data) == END)
			break ;
		if (data->must_eat > -1 && philo->eat_cnt == data->must_eat)
			break ;
		if (_ph_sleep_and_think(philo, data) == END)
			break ;
		usleep(500);
	}
	return (NULL);
}

static int	_ph_eat(t_philo *philo, t_data *data)
{
	if (_ph_pick_fork(philo, data) == END)
		return (END);
	if (_ph_is_eating(philo, data, current_time()) == END)
		return (END);

	pthread_mutex_lock(&data->f_state[philo->left]);
	data->forks[philo->left] = FALSE;
	pthread_mutex_unlock(&data->f_state[philo->left]);

	pthread_mutex_lock(&data->f_state[philo->right]);
	data->forks[philo->right] = FALSE;
	pthread_mutex_unlock(&data->f_state[philo->right]);

	return (CONTINUE);
}

static int	_ph_pick_fork(t_philo *philo, t_data *data)
{
	while (check_ph_dead(philo, data) == FALSE)
	{
		pthread_mutex_lock(&data->f_state[philo->left]);
		pthread_mutex_lock(&data->f_state[philo->right]);
		if (data->forks[philo->left] == FALSE && data->forks[philo->right] == FALSE)
		{
			data->forks[philo->left] = TRUE;
			data->forks[philo->right] = TRUE;
			print_message(philo, FORK);
			print_message(philo, FORK);
			pthread_mutex_unlock(&data->f_state[philo->left]);
			pthread_mutex_unlock(&data->f_state[philo->right]);
			return (CONTINUE);
		}
		pthread_mutex_unlock(&data->f_state[philo->left]);
		pthread_mutex_unlock(&data->f_state[philo->right]);
	}
	return (END);
}

static int	_ph_is_eating(t_philo *philo, t_data *data, long long eat_start)
{
	print_message(philo, EAT);
	while (current_time() - eat_start < data->eat_t)
	{
		if (check_ph_dead(philo, data) == TRUE)
		{
			data->forks[philo->left] = FALSE;
			pthread_mutex_unlock(&data->f_state[philo->left]);
			data->forks[philo->right] = FALSE;
			pthread_mutex_unlock(&data->f_state[philo->right]);
			return (END);
		}
	}
	philo->last_eat = current_time();
	++philo->eat_cnt;
	return (CONTINUE);
}

static int	_ph_sleep_and_think(t_philo *philo, t_data *data)
{
	print_message(philo, SLEEP);
	while (current_time() - philo->last_eat < data->sleep_t)
		if (check_ph_dead(philo, data) == TRUE)
			return (END);
	print_message(philo, THINK);
	if (check_ph_dead(philo, data) == TRUE)
			return (END);
	return (CONTINUE);
}
