/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:38:36 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/28 20:11:04 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo(t_philo *philo, int philosophers)
{
	int	i;

	if (philo == NULL)
		return ;
	i = 0;
	while (i < philosophers)
		pthread_join(philo[i++].tid, NULL);
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
