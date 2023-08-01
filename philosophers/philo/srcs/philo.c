/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:16:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/31 16:14:18 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		errno;

	if (ac < 5 || ac > 7)
		return (error_message("Error: invalid arguments\n"));
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	errno = init_data(data, ac, av);
	if (data == NULL)
		return (error_message("Error: fail to init struct(data)\n"));

	return (EXIT_SUCCESS);
}
