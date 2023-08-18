/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 18:50:31 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	error_exit(t_philo *philo, t_data *data, int errno)
{
	if (philo != NULL && data != NULL)
		free_philo(philo, data->philosophers);
	free_data(data);
	if (errno == ALLOC_FAIL)
		exit (EXIT_FAILURE);
	else if (errno == ARG_ERR)
		ft_putstr_fd("Error: invalid arguments\n", STDERR_FILENO);
	else if (errno == SEM_ERR)
		ft_putstr_fd("Error: failed to initialize semaphore\n", STDERR_FILENO);
	else if (errno == PHILO_ERR)
		ft_putstr_fd("Error: failed to create philo\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}
