/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 00:38:36 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/12 02:18:23 by jihykim2         ###   ########.fr       */
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
	if (data->forks != NULL)
		free (data->forks);
	if (data->f_state != NULL)
	{
		i = 0;
		while (i < data->philosophers)
			pthread_mutex_destroy(&data->f_state[i++]);
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->dead_philo);
		free (data->f_state);
	}
	free (data);
}
