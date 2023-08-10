/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/10 10:47:37 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_monitoring_philo(t_philo *philo, t_data *data);

int	start_philo(t_data *data)
{
	t_philo	*philo;
	int		i;
	int		status;

	philo = init_philo(data);
	if (philo == NULL)
		return (PHILO_ERR);		// 여기서는 philo가 생성되지 않음 >> data_err
	data->start = get_time();
	i = 0;
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]) != 0)
			return (PHILO_ERR);		// philo가 생성되어 있는 상태.. (따로 에러처리)
		i++;
	}
	while (TRUE)
	{
		status = _monitoring_philo(philo, data);
		if (status != SUCCESS)
			break ;
	}
	finish_philo(philo, data);
}

static int	_monitoring_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->end_philo);
	if (data->must_eat > -1 && data->end == data->philosophers)
	{
		pthread_mutex_unlock(&data->end_philo);
		return (PHILO_END);
	}
	pthread_mutex_unlock(&data->end_philo);
	pthread_mutex_lock(&data->die_philo);
	if (data->dead != 0)
	{// 모든 philo마다 시간 차이 확인해서 죽었는지 확인하기...
		pthread_mutex_unlock(&data->die_philo);
		return (PHILO_DEAD);
	}
	pthread_mutex_unlock(&data->die_philo);
	return (SUCCESS);
}
