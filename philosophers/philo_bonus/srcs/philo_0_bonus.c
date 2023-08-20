/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_0_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:09:05 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 15:00:49 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	check_leaks(void)
{
	system("leaks --quiet philo");
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	// atexit(check_leaks);
	if (ac < 5 || ac > 6)
		error_exit(NULL, ARG_ERR);
	philo = init_philo(ac, av);

	create_child_proc(philo);
	wait_and_check_child(philo);
	free_philo(philo);
	return (EXIT_SUCCESS);
}
