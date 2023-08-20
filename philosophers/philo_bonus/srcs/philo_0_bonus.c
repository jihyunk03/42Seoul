/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_0_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:09:05 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 21:07:15 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		i;

	if (ac < 5 || ac > 6)
		error_exit(NULL, ARG_ERR);
	philo = init_philo(ac, av);

	i = 0;
	philo->start_t = current_time();
	while (i < philo->philosophers)
	{
		philo->id = i + 1;
		philo->philo_id = ft_itoa(philo->id);
		if (philo->philo_id == NULL)
			exit (ALLOC_FAIL);
		philo->child_id[i] = fork();
		if (philo->child_id[i] < 0)
			error_exit(philo, FORK_ERR);
		else if (philo->child_id[i] == 0)
			child_routine(philo);
		free (philo->philo_id);
		i++;
	}

	wait_and_check_child(philo);
	free_philo(philo);
	exit (EXIT_SUCCESS);
}
