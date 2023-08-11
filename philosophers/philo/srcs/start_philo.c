/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/11 20:16:17 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static int	_is_ph_died(t_philo *philo, t_data *data);
// static int	_is_ph_end(t_data *data);

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
	// while (TRUE)
	// 	if (_is_ph_died(philo, data) == TRUE || _is_ph_end(data) == TRUE)
	// 		break ;
	free_philo(philo, data->philosophers);
	free_data(data);
	return (EXIT_SUCCESS);
}

// static int	_is_ph_died(t_philo *philo, t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	// pthread_mutex_lock(&data->dead_philo);
// 	while (i < data->philosophers)
// 	{
// 		if (philo[i].last_eat && philo[i].full == FALSE \
// 			&& current_time() - philo[i].last_eat > data->die_t)
// 		{
// 			print_message(&philo[i], DEAD);
// 			pthread_mutex_lock(&data->dead_philo);
// 			data->dead = TRUE;
// 			pthread_mutex_unlock(&data->dead_philo);
// 			return (TRUE);
// 		}
// 		i++;
// 	}
// 	// pthread_mutex_unlock(&data->dead_philo);
// 	return (FALSE);
// }

// static int	_is_ph_end(t_data *data)
// {
// 	if (data->must_eat == -1)
// 		return (FALSE);
// 	pthread_mutex_lock(&data->end_philo);
// 	if (data->end == data->philosophers)
// 	{
// 		pthread_mutex_unlock(&data->end_philo);
// 		return (TRUE);
// 	}
// 	pthread_mutex_unlock(&data->end_philo);
// 	return (FALSE);
// }
