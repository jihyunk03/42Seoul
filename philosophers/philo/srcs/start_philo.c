/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/11 20:44:45 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_philo(t_philo *philo, t_data *data)
{
	int		i;

	data->start_t = current_time();
	i = 0;
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]) != 0)
			return (error_exit(philo, data, PHILO_ERR));
		i++;
	}
	free_philo(philo, data->philosophers);
	free_data(data);
	return (EXIT_SUCCESS);
}
