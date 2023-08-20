/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_child_process_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:10:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 21:44:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	*_child_monitor(void *ph);
static void	_ph_eat(t_philo *philo);
static void	_ph_sleep_and_think(t_philo *philo);
static void	_exit_child_with_status(t_philo *philo, int mode, int exit_code);

void	child_routine(t_philo *philo)
{
	free (philo->child_id);
	sem_unlink(philo->philo_id);
	philo->data_lock = sem_open(philo->philo_id, O_CREAT, 0, 1);
	if (philo->data_lock == SEM_FAILED)
		_exit_child_with_status(philo, FALSE, SEM_ERR);
	philo->last_eat = current_time();
	if (pthread_create(&philo->monitor, NULL, _child_monitor, philo) != 0)
		_exit_child_with_status(philo, FALSE, THREAD_ERR);
	pthread_detach(philo->monitor);
	if (philo->id % 2 == 0)
		usleep(sleep_even_philo(philo->die_t, philo->eat_t));
	while (TRUE)
	{
		_ph_eat(philo);
		if (philo->must_eat > 0 && philo->eat_cnt == philo->must_eat)
			_exit_child_with_status(philo, FALSE, EAT_END);
		_ph_sleep_and_think(philo);
		usleep(500);
	}
}

static void	*_child_monitor(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (TRUE)
	{
		sem_wait(philo->data_lock);
		if (current_time() - philo->last_eat >= philo->die_t)
			_exit_child_with_status(philo, TRUE, philo->id);
		sem_post(philo->data_lock);
		usleep(300);
	}
}

static void	_ph_eat(t_philo *philo)
{
	long long	last_time;

	sem_wait(philo->forks);
	print_message(philo, FORK);
	sem_wait(philo->forks);
	print_message(philo, FORK);
	print_message(philo, EAT);
	sem_wait(philo->data_lock);
	philo->last_eat = current_time();
	last_time = philo->last_eat;
	sem_post(philo->data_lock);
	while (current_time() - last_time <= philo->eat_t)
		usleep(500);
	// usleep(philo->eat_t * 1000);
	sem_post(philo->forks);
	sem_post(philo->forks);
	philo->eat_cnt++;
}

static void	_ph_sleep_and_think(t_philo *philo)
{
	long long	start_time;

	print_message(philo, SLEEP);
	start_time = current_time();
	while (current_time() - start_time <= philo->sleep_t)
		usleep(300);
	// usleep(philo->sleep_t * 1000);
	print_message(philo, THINK);
}

static void	_exit_child_with_status(t_philo *philo, int mode, int exit_code)
{
	if (mode == TRUE)
		sem_post(philo->data_lock);
	sem_close(philo->data_lock);
	free (philo->philo_id);
	exit (exit_code);
}
