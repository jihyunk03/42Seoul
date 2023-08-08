/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:16:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/08 18:25:24 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		errno;

	if (ac < 5 || ac > 6)
		return (error_message("Error: invalid arguments\n"));

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	errno = init_data(data, ac, av);
	if (errno != SUCCESS)
		return (error_message("Error: fail to init struct(data)\n"));

	errno = start_philo(data);
	if (errno != SUCCESS)
		return (error_message("Error: fail to threading\n"));

	return (EXIT_SUCCESS);
}
