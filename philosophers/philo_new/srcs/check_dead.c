/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:20:07 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/16 04:09:49 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_dead(t_philo *philo, t_data *data)
{
	if (philo_dead(philo, data) == TRUE || someone_dead(data) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	philo_dead(t_philo *philo, t_data *data)
{
	if (current_time() - philo->last_eat > data->die_t)
	{
		print_dead(philo, data);
		pthread_mutex_lock(&data->dead_philo);
		data->dead = TRUE;
		pthread_mutex_unlock(&data->dead_philo);
		return (TRUE);
	}
	return (FALSE);
}

int	someone_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead_philo);
	if (data->dead == TRUE)
	{
		pthread_mutex_unlock(&data->dead_philo);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->dead_philo);
	return (FALSE);
}
