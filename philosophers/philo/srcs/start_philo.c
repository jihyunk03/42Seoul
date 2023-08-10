/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/11 02:50:54 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_monitoring_philo(t_philo *philo, t_data *data);

int	start_philo(t_philo *philo, t_data *data)
{
	int		i;

	data->start = current_time();
	i = 0;
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]) != 0)
			return (error_exit(philo, data, PHILO_ERR));
		i++;
	}
	while (TRUE)
		if (_monitoring_philo(philo, data) == END)
			break ;
	free_philo(philo, data->philosophers);
	free_data(data);
	return (EXIT_SUCCESS);
}

static int	_monitoring_philo(t_philo *philo, t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->end_philo);
	if (data->must_eat > -1 && data->end == data->philosophers)
	{
		pthread_mutex_unlock(&data->end_philo);
		return (END);
	}
	pthread_mutex_unlock(&data->end_philo);
	i = 0;
	while (i < data->philosophers)
	{
		if (current_time() - philo[i].last_eat > data->die_t)
		{
			pthread_mutex_lock(&data->die_philo);
			data->dead = TRUE;
			print_message(&philo[i], DEAD);
			pthread_mutex_unlock(&data->die_philo);
			return (END);
		}
		i++;
	}
	return (CONTINUE);
}
