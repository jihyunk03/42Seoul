/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3_routine_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:11:01 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 22:00:37 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	child_routine(t_philo *philo)
{
	philo->philo_name = ft_itoa(philo->id);
	if (philo->philo_name == NULL)
		exit (ALLOC_FAIL);
	sem_unlink(philo->philo_name);
	philo->philo_time = sem_open(philo->philo_name, O_CREAT, 0644, 1);
	if (philo->philo_time == SEM_FAILED)
		exit (SEM_ERR);

	philo->last_eat = current_time();
	if (philo->id % 2 == 0)
		usleep(sleep_even_philo(philo->die_t, philo->eat_t));

	if (pthread_create(&philo->monitor, NULL, _child_monitor, philo) != 0)
		exit (THREAD_ERR);
	while (TRUE)
	{
		_ph_eat();
		_ph_sleep_and_think();
	}
}
