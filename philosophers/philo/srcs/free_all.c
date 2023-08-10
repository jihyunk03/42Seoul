/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:29:52 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/09 17:55:20 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
}

void	free_philo(t_philo **philo, int cnt)
{
	int	i;

	if (philo == NULL)
		return ;
	i = 0;
	while (i < cnt)
		free (philo[i++]);
	free (philo);	// ?? 맞나..?
}
