/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:09:23 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 20:44:56 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	error_exit(t_philo *philo, int errno)
{
	if (philo != NULL)
		free_philo(philo);
	if (errno == ALLOC_FAIL)
		exit (EXIT_FAILURE);
	else if (errno == ARG_ERR)
		ft_putstr_fd("Error: invalid arguments\n", STDERR_FILENO);
	else if (errno == SEM_ERR)
		ft_putstr_fd("Error: failed to initialize semaphore\n", STDERR_FILENO);
	else if (errno == THREAD_ERR)
		ft_putstr_fd("Error: failed to create thread\n", STDERR_FILENO);
	else if (errno == FORK_ERR)
		ft_putstr_fd("Error: failed to create child process\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	free_philo(t_philo *philo)
{
	if (philo == NULL)
		return ;
	if (philo->forks != NULL)
		sem_close(philo->forks);
	if (philo->print != NULL)
		sem_close(philo->print);
	if (philo->child_id != NULL)
		free (philo->child_id);
	free (philo);
}
