/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_print_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:04:11 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 17:20:23 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_message(t_philo *philo, char *message)
{
	sem_wait(philo->data->print);
	if (philo->data->no_print == TRUE)
	{
		sem_post(philo->data->print);
		return ;
	}
	printf("%lld %d %s\n", current_time() - philo->data->start_t, \
	philo->id, message);
	sem_post(philo->data->print);
}

void	print_dead(t_philo *philo, t_data *data)
{
	sem_wait(data->print);
	if (data->no_print == TRUE)
	{
		sem_post(data->print);
		return ;
	}
	data->no_print = TRUE;
	printf("%lld %d %s\n", current_time() - data->start_t, \
	philo->id, DEAD);
	sem_post(data->print);
}
