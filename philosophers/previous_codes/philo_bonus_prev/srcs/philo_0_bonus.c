/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_0_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:07:27 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 17:20:23 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		errno;

	if (ac < 5 || ac > 6)
		error_exit(NULL, NULL, ARG_ERR);

	data = init_data(ac, av);
	philo = init_philo(data);

	return (start_philo(philo, data));
}
