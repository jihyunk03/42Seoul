/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:38:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/16 04:08:16 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->print_dead_flag == TRUE \
	|| someone_dead(philo->data) == TRUE)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	printf("%lld %d %s\n", current_time() - philo->data->start_t, \
	philo->id, message);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->print);
	if (data->print_dead_flag == TRUE)
	{
		pthread_mutex_unlock(&data->print);
		return ;
	}
	data->print_dead_flag = TRUE;
	printf("%lld %d %s\n", current_time() - data->start_t, \
	philo->id, DEAD);
	pthread_mutex_unlock(&data->print);
}
