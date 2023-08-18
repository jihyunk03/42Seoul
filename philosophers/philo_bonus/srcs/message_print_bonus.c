/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_print_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:04:11 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 19:15:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->no_print == TRUE)
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
	if (data->no_print == TRUE)
	{
		pthread_mutex_unlock(&data->print);
		return ;
	}
	data->no_print = TRUE;
	printf("%lld %d %s\n", current_time() - data->start_t, \
	philo->id, DEAD);
	pthread_mutex_unlock(&data->print);
}
