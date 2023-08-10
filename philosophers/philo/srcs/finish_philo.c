/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:08:48 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/10 14:38:48 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	finish_philo(t_philo *philo, t_data *data)
{
	int	i;

	// ?? 어떻게 종료하지...?
	i = 0;
	while (i < data->philosophers)
		pthread_join(&philo[i++].tid, 0);
	i = 0;
	while (i < data->philosophers)
		pthread_mutex_destroy(&data->f_state[i++]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->end_philo);
	pthread_mutex_destroy(&data->die_philo);
	free_data(data);
	free_philo(&philo);
}
