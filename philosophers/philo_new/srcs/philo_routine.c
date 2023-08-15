/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:58:42 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/16 08:01:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_ph_pick_up_forks(t_philo *philo, t_data *data);
static int	_ph_eating(t_philo *philo, t_data *data, long long start_time);
static void	_ph_put_down_forks(t_philo *philo, t_data *data);

int	ph_eat(t_philo *philo, t_data *data)
{
	int	ret;

	ret = CONTINUE;
	if (_ph_pick_up_forks(philo, data) == FALSE)
		return (END);
	if (_ph_eating(philo, data, current_time()) == FALSE)
		ret = END;
	_ph_put_down_forks(philo, data);
	if (data->must_eat > 0 && philo->eat_cnt == data->must_eat)
		return (END);
	return (ret);
}

static int	_ph_pick_up_forks(t_philo *philo, t_data *data)
{// 짝수 홀수번째 포크 순서를 init에서 바꿔버릴까...?
	while (check_dead(philo, data) == FALSE)
	{
		pthread_mutex_lock(&data->f_state[philo->left]);
		if (data->forks[philo->left] == USING)
		{
			pthread_mutex_unlock(&data->f_state[philo->left]);
			usleep(100);
			continue ;
		}
		pthread_mutex_lock(&data->f_state[philo->right]);
		if (data->forks[philo->right] == AVAILABLE)
		{
			data->forks[philo->left] = USING;
			print_message(philo, FORK);
			data->forks[philo->right] = USING;
			print_message(philo, FORK);
			pthread_mutex_unlock(&data->f_state[philo->left]);
			pthread_mutex_unlock(&data->f_state[philo->right]);
			return (TRUE);
		}
		pthread_mutex_unlock(&data->f_state[philo->left]);
		pthread_mutex_unlock(&data->f_state[philo->right]);
		usleep(200);
	}
	return (FALSE);
}

static int	_ph_eating(t_philo *philo, t_data *data, long long start_time)
{
	if (check_dead(philo, data) == TRUE)
		return (FALSE);
	print_message(philo, EAT);
	philo->last_eat = current_time();
	usleep(data->eat_t * 800);
	while (current_time() - start_time < data->eat_t)
	{
		if (someone_dead(data) == TRUE)
			return (FALSE);
		usleep(200);
	}
	philo->eat_cnt++;
	if (check_dead(philo, data) == TRUE)
		return (FALSE);
	return (TRUE);
}

static void	_ph_put_down_forks(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->f_state[philo->right]);
	data->forks[philo->right] = AVAILABLE;
	pthread_mutex_unlock(&data->f_state[philo->right]);
	pthread_mutex_lock(&data->f_state[philo->left]);
	data->forks[philo->left] = AVAILABLE;
	pthread_mutex_unlock(&data->f_state[philo->left]);
}

int	ph_sleep_and_think(t_philo *philo, t_data *data)
{
	long long	time;
	if (check_dead(philo, data) == TRUE)
		return (END);
	print_message(philo, SLEEP);
	time = current_time();
	while (current_time() - time < data->sleep_t)
		usleep(200);
	if (check_dead(philo, data) == TRUE)
		return (END);
	print_message(philo, THINK);
	return (CONTINUE);
}
