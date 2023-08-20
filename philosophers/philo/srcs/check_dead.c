/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:20:07 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 22:22:42 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_dead(t_philo *philo, t_data *data)
{
	if (someone_dead(data) == TRUE || philo_dead(philo, data) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	philo_dead(t_philo *philo, t_data *data)
{
	if (current_time() - philo->last_eat >= data->die_t)
	{
		print_dead(philo, data);
		pthread_mutex_lock(&data->dead);
		data->someone_dead = TRUE;
		pthread_mutex_unlock(&data->dead);
		return (TRUE);
	}
	return (FALSE);
}

int	someone_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead);
	if (data->someone_dead == TRUE)
	{
		pthread_mutex_unlock(&data->dead);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->dead);
	return (FALSE);
}
