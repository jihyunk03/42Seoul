/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:38:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/10 12:15:00 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld\t%d %s\n", current_time() - philo->data->start, \
		philo->id, message);
	pthread_mutex_unlock(&philo->data->print);
}

int	check_dead(t_data *data)
{
	pthread_mutex_lock(&data->die_philo);
	if (data->dead == TRUE)
	{
		pthread_mutex_unlock(&data->die_philo);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->die_philo);
	return (FALSE);
}
