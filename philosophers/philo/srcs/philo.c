/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:16:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/06 15:28:30 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		errno;

	if (ac < 5 || ac > 7)
		return (error_message("Error: invalid arguments\n"));

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	memset(data, 0, sizeof(t_data));
	errno = init_data(data, ac, av);
	if (errno != SUCCESS)
		return (error_message("Error: fail to init struct(data)\n"));

	philo = init_philo(data);
	if (philo == NULL)
		return (error_message("Error: fail to init_philo\n"));

	_make_thread(philo, data->philosophers);
	return (EXIT_SUCCESS);
}

static int	_make_thread(t_philo *philo, int philosophers)
{
	int		i;

	i = 0;
	while (i < philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, start_philo, &philo[i]) != 0)
			return (PHILO_ERR);
		i++;
	}
}

int	start_philo(t_philo *philo)
{

}
