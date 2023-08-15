/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:16:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/14 17:31:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	start_philo(t_philo *philo, t_data *data);

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		errno;

	if (ac < 5 || ac > 6)
		return (error_message("Error: arguments must be 5 ~ 6\n"));
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	errno = init_data(data, ac, av);
	if (errno != SUCCESS)
		return (error_exit(NULL, data, errno));
	philo = init_philo(data);
	if (philo == NULL)
		return (error_exit(NULL, data, ALLOC_FAIL));
	return (start_philo(philo, data));
}

static int	start_philo(t_philo *philo, t_data *data)
{
	int		i;

	data->start_t = current_time();
	i = 0;
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]) != 0)
			return (error_exit(philo, data, PHILO_ERR));
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]) != 0)
			return (error_exit(philo, data, PHILO_ERR));
		i += 2;
	}
	free_philo(philo, data->philosophers);
	free_data(data);
	return (EXIT_SUCCESS);
}
