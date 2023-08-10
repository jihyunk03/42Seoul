/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/10 14:34:36 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_monitoring_philo(t_philo *philo, t_data *data);

int	start_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = init_philo(data);
	if (philo == NULL)
		return (PHILO_ERR);		// 여기서는 philo가 생성되지 않음 >> data_err
	data->start = current_time();
	i = 0;
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]) != 0)
			return (PHILO_ERR);		// philo가 생성되어 있는 상태.. (따로 에러처리)
		i++;
	}
	while (TRUE)
		if (_monitoring_philo(philo, data) == END)
			break ;
	finish_philo(philo, data);
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
