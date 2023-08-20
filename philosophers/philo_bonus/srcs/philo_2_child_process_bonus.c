/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_child_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:10:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 14:35:46 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	_child_routine(t_philo *philo);
static void	*_child_monitor(void *ph);

void	create_child_proc(t_philo *philo)
{
	int		i;

	i = 0;
	philo->start_t = current_time();
	while (i < philo->philosophers)
	{
		philo->id = i + 1;
		philo->child_id[i] = fork();
		if (philo->child_id[i] < 0)
			error_exit(philo, FORK_ERR);
		else if (philo->child_id[i] == 0)
			_child_routine(philo);
		i++;
	}
}

static void	_child_routine(t_philo *philo)
{
	philo->philo_id = ft_itoa(philo->id);
	if (philo->philo_id == NULL)
		exit (ALLOC_FAIL);
	sem_unlink(philo->philo_id);
	philo->data_lock = sem_open(philo->philo_id, O_CREAT, 0644, 1);
	if (philo->data_lock == SEM_FAILED)
		exit (SEM_ERR);

	philo->last_eat = current_time();
	if (philo->id % 2 == 0)
		usleep(sleep_even_philo(philo->die_t, philo->eat_t));

	if (pthread_create(&philo->monitor, NULL, _child_monitor, philo) != 0)
		exit (THREAD_ERR);

	while (TRUE)
	{
		ph_eat(philo);
		ph_sleep_and_think(philo);
		usleep(300);
	}
}

static void	*_child_monitor(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (TRUE)
	{
		usleep(300);
		sem_wait(philo->data_lock);
		if (current_time() - philo->last_eat > philo->die_t)
			exit_child_with_status(philo, TRUE, DEAD_END);
		sem_post(philo->data_lock);
	}
}
