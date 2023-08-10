/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 08:52:17 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/09 17:34:22 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_ph_eat(t_philo *philo);
static int	_ph_sleep(t_philo *philo);
static int	_ph_think(t_philo *philo);

void	*start_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	philo->last_eat = get_time();
	if (philo->eat_cnt == 0 && philo->id % 2 == 0)
		usleep(100);	// die_t 고려해서 다시 시간 정할 것
	while (TRUE)
	{
		if (_ph_eat(philo) == FALSE || philo->full == TRUE)
			return (NULL);
		if (_ph_sleep(philo) == FALSE)
			return (NULL);
		if (_ph_think(philo) == FALSE)
			return (NULL);
	}
	// return (NULL);
}

static int	_ph_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->f_state[philo->left]);

	print_message(philo, FORK);
	pthread_mutex_lock(&philo->data->f_state[philo->right]);
	print_message(philo, FORK);
	while (get_time() - philo->last_eat < philo->data->eat_t)
		if (philo->data->dead == TRUE)
			return ;	// return 값이 없어서 그냥 종료하고 monitoring에서 잡힐 것이라 예상중 ^^
	if (++(philo->eat_cnt) == philo->data->must_eat)
		philo->full = TRUE;
	print_message(philo, EAT);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->data->f_state[philo->left]);
	pthread_mutex_unlock(&philo->data->f_state[philo->right]);
}

static int	_ph_sleep(t_philo *philo)
{

}

static int	_ph_think(t_philo *philo)
{

}
