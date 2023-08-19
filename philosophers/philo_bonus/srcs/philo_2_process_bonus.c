/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:10:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 21:33:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
			child_routine(philo);
		i++;
	}
}

void	wait_and_check_child(t_philo *philo)
{
	int	i;
	int	status;
	int	exit_code;

	i = 0;
	while (i < philo->philosophers)
	{
		waitpid(-1, &status, 0);
		exit_code = WEXITSTATUS(status);
		if (exit_code != EAT_END)
		{
			i = 0;
			while (i < philo->philosophers)
				kill(philo->child_id[i++], SIGINT);
			if (exit_code != DEAD_END)
				error_exit(philo, exit_code);
			return ;
		}
		i++;
	}
}
