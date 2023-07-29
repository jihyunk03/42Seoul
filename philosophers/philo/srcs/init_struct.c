/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:44:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/28 20:26:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*init_data(int ac, char **av)
{
	t_data	*new_data;

	new_data = malloc(sizeof(new_data));
	if (new_data == NULL)
		return (NULL);
	new_data->philosophers = ft_atoi(av[1]);
	new_data->die_t = ft_atoi(av[2]);
	new_data->eat_t = ft_atoi(av[3]);
	new_data->sleep_t = ft_atoi(av[4]);
	if (ac == 6)
		new_data->must_eat = ft_atoi(av[5]);
	else
		new_data->must_eat = 0;

}

