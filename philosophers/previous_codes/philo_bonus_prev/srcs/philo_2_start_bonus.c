/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_start_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:06:20 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 17:20:23 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	_one_philo_routine(t_philo *philo, t_data *data);

int	start_philo(t_philo *philo, t_data *data)
{
	int	i;
	int	status;

	i = 0;
	data->start_t = current_time();
	while (i < data->philosophers)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			exit (EXIT_FAILURE);
		else if (philo[i].pid == 0)
			_start_routine(philo, data);		// child process
		i++;
	}
	while (i--)	// parent process
	{
		waitpid(-1, &status, 0);		// 어느 누구하나라도 종료 시 코드 반환
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			exit_others();
	}
	free_philo(philo, data->philosophers);
	free_data(data);
	exit (EXIT_SUCCESS);
}

static int	_start_routine(t_philo *philo, t_data *data)
{
	philo->last_eat = data->start_t;
	if (data->philosophers == 1)
		_one_philo_routine(philo, data);
	if (philo->id % 2 == 0)
		usleep(sleep_even_philo(data));
	if (pthread_create(&philo->monitor, NULL, _monitoring, philo) != 0)
		exit (EXIT_FAILURE);
	while (TRUE)
	{
		ph_eat(philo, data);
		if (philo->eat_cnt == data->must_eat)
			break ;
		ph_sleep_and_think(philo, data);
		usleep(200);
	}
	exit (EXIT_SUCCESS);
}

static int	_one_philo_routine(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	data->fork_count--;
	print_message(philo, FORK);
	sem_post(data->forks);
	while (current_time() - data->start_t < data->die_t)
		usleep(500);
	print_dead(philo, data);
	sem_wait(data->forks);
	data->fork_count++;
	sem_post(data->forks);
	exit (EXIT_FAILURE);	// kill에 대해 다시 자세히 알아볼것
}

static void	*_monitoring(void *ph)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ph;
	data = philo->data;
	while (TRUE)
	{

	}
}
