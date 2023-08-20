/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_print_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:10:25 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 14:39:15 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_message(t_philo *philo, char *message)
{
	sem_wait(philo->print);
	if (philo->no_print == TRUE)
	{
		sem_post(philo->print);
		return ;
	}
	printf("%lld %d %s\n", current_time() - philo->start_t, \
	philo->id, message);
	sem_post(philo->print);
}

void	print_dead(t_philo *philo)
{
	sem_wait(philo->print);
	if (philo->no_print == TRUE);
	{
		sem_post(philo->print);
		return ;
	}
	printf("%lld %d %s\n", current_time() - philo->start_t, \
	philo->id, DEAD);
	sem_post(philo->print);
}
