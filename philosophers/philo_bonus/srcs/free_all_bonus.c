/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:09:32 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 14:58:16 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
