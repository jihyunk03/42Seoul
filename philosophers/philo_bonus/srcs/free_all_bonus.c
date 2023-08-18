/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:51:57 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 17:53:47 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	free_philo(t_philo *philo, int philosophers)
{
	if (philo == NULL)
		return ;
	free (philo);
}

void	free_data(t_data *data)
{
	int	i;

	if (data == NULL)
		return ;
	if (data->fork_state != NULL)
		free (data->fork_state);
	if (data->forks != NULL)
	{
		i = 0;
		while (i < data->philosophers)
			pthread_mutex_destroy(&data->forks[i++]);
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->dead);
		free (data->forks);
	}
	free (data);
}
