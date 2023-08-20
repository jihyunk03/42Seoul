/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_parent_process_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:30:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 21:02:07 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	kill_all_process(t_philo *philo, int exit_code);

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
			kill_all_process(philo, exit_code);
			return ;
		}
		i++;
	}
}

static void	kill_all_process(t_philo *philo, int exit_code)
{
	int	i;

	i = 0;
	while (i < philo->philosophers)
		kill(philo->child_id[i++], SIGINT);
	if (exit_code == SEM_ERR || exit_code == THREAD_ERR)
		error_exit(philo, exit_code);
	printf("%lld %d %s\n", current_time() - philo->start_t, exit_code, DEAD);
}
