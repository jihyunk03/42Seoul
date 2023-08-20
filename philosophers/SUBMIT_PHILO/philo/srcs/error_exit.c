/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/15 16:01:48 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_message(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	error_exit(t_philo *philo, t_data *data, int errno)
{
	if (philo != NULL && data != NULL)
		free_philo(philo, data->philosophers);
	free_data(data);
	if (errno == ALLOC_FAIL)
		return (EXIT_FAILURE);
	else if (errno == ARG_ERR)
		return (error_message("Error: invalid arguments\n"));
	else if (errno == MUTEX_ERR)
		return (error_message("Error: failed to initialize mutex\n"));
	else if (errno == PHILO_ERR)
		return (error_message("Error: failed to create philo\n"));
	return (EXIT_FAILURE);
}
