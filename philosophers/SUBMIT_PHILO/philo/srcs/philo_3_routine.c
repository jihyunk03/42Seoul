/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:58:42 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 22:19:55 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_ph_pick_up_forks(t_philo *philo, t_data *data);
static int	_ph_eating(t_philo *philo, t_data *data);
static void	_ph_put_down_forks(t_philo *philo, t_data *data);

int	ph_eat(t_philo *philo, t_data *data)
{
	int	ret;

	ret = CONTINUE;
	if (_ph_pick_up_forks(philo, data) == FALSE)
		return (END);
	if (_ph_eating(philo, data) == FALSE)
		ret = END;
	_ph_put_down_forks(philo, data);
	if (data->must_eat > 0 && philo->eat_cnt == data->must_eat)
		return (END);
	return (ret);
}

static int	_ph_pick_up_forks(t_philo *philo, t_data *data)
{
	while (check_dead(philo, data) == FALSE)
	{
		pthread_mutex_lock(&data->forks[philo->left]);
		if (data->fork_state[philo->left] == USING)
		{
			pthread_mutex_unlock(&data->forks[philo->left]);
			usleep(300);
			continue ;
		}
		pthread_mutex_lock(&data->forks[philo->right]);
		if (data->fork_state[philo->right] == AVAILABLE)
		{
			data->fork_state[philo->left] = USING;
			print_message(philo, FORK);
			data->fork_state[philo->right] = USING;
			print_message(philo, FORK);
			pthread_mutex_unlock(&data->forks[philo->left]);
			pthread_mutex_unlock(&data->forks[philo->right]);
			return (TRUE);
		}
		pthread_mutex_unlock(&data->forks[philo->left]);
		pthread_mutex_unlock(&data->forks[philo->right]);
		usleep(200);
	}
	return (FALSE);
}

static int	_ph_eating(t_philo *philo, t_data *data)
{
	if (check_dead(philo, data) == TRUE)
		return (FALSE);
	print_message(philo, EAT);
	philo->last_eat = current_time();
	while (current_time() - philo->last_eat <= data->eat_t * 0.8 \
	&& check_dead(philo, data) == FALSE)
		usleep(500);
	while (current_time() - philo->last_eat <= data->eat_t \
	&& check_dead(philo, data) == FALSE)
		usleep(100);
	if (someone_dead(data) == TRUE)
		return (FALSE);
	philo->eat_cnt++;
	return (TRUE);
}

static void	_ph_put_down_forks(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->right]);
	data->fork_state[philo->right] = AVAILABLE;
	pthread_mutex_unlock(&data->forks[philo->right]);
	pthread_mutex_lock(&data->forks[philo->left]);
	data->fork_state[philo->left] = AVAILABLE;
	pthread_mutex_unlock(&data->forks[philo->left]);
}

int	ph_sleep_and_think(t_philo *philo, t_data *data)
{
	long long	time;

	if (check_dead(philo, data) == TRUE)
		return (END);
	print_message(philo, SLEEP);
	time = current_time();
	while (current_time() - time <= data->sleep_t)
	{
		if (check_dead(philo, data) == TRUE)
			return (END);
		usleep(300);
	}
	print_message(philo, THINK);
	return (CONTINUE);
}
