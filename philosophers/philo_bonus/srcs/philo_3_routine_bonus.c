/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3_routine_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:11:01 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 00:41:32 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	*_child_monitor(void *ph);

void	child_routine(t_philo *philo)
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
	}
}

static void	*_child_monitor(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;

}

void	ph_eat(t_philo *philo)
{
	ph_pick_up_forks(philo);
	ph_eating(philo);
	ph_put_down_forks(philo);
}

void	ph_pick_up_forks(t_philo *philo)
{
	while (TRUE)
	{
		sem_wait(philo->forks);
		if (philo->fork_count < 2)
		{
			sem_post(philo->forks);
			usleep(300);
			continue ;
		}
		sem_wait(philo->forks);
		philo->fork_count -= 2;
		print_message(philo, FORK);
		print_message(philo, FORK);
		sem_post(philo->forks);
		sem_post(philo->forks);
		return ;
	}
}

void	ph_eating(t_philo *philo)
{
	long long	last_time;

	print_message(philo, EAT);
	sem_wait(philo->data_lock);
	philo->last_eat = current_time();
	last_time = philo->last_eat;
	sem_post(philo->data_lock);
	while (current_time() - last_time < philo->eat_t)
		usleep(500);		// 어차피 모니터링에서 끝내줄거라 상관 없,,,? 그냥 자체로 usleep은 안되겠지...?
	sem_wait(philo->data_lock);
	philo->eat_cnt++;
	sem_post(philo->data_lock);

}
