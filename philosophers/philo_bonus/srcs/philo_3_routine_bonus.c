/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3_routine_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:11:01 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 14:56:50 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	_ph_pick_up_forks(t_philo *philo);
static void	_ph_eating(t_philo *philo);
static void	_ph_put_down_forks(t_philo *philo);

void	ph_eat(t_philo *philo)
{
	_ph_pick_up_forks(philo);
	_ph_eating(philo);
	_ph_put_down_forks(philo);
	if (philo->eat_cnt == philo->must_eat)
		exit_child_with_status(philo, FALSE, EAT_END);
}

static void	_ph_pick_up_forks(t_philo *philo)
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

static void	_ph_eating(t_philo *philo)
{
	long long	last_time;

	print_message(philo, EAT);
	sem_wait(philo->data_lock);
	philo->last_eat = current_time();
	last_time = philo->last_eat;
	sem_post(philo->data_lock);
	while (current_time() - last_time < philo->eat_t)
		usleep(500);		// 어차피 모니터링에서 끝내줄거라 상관 없,,,? 그냥 자체로 usleep은 안되겠지...?
	philo->eat_cnt++;
}

static void	_ph_put_down_forks(t_philo *philo)
{
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	philo->fork_count += 2;
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	ph_sleep_and_think(t_philo *philo)
{
	long long	start_time;

	print_message(philo, SLEEP);
	start_time = current_time();
	while (current_time() - start_time <= philo->sleep_t)
		usleep(300);
	print_message(philo, THINK);
}
