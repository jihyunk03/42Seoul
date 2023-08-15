/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:58:42 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/16 04:55:57 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ph_eat(t_philo *philo, t_data *data)
{
	if (_ph_pick_up_forks(philo, data) == FALSE)
		return (END);
	if (_ph_eating(philo, data) == FALSE)
		return (END);
	if (check_dead(philo, data) == TRUE)
		return (END);
	_ph_put_down_forks(philo, data);
	return (CONTINUE);
}

int	ph_sleep_and_think(t_philo *philo, t_data *data)
{

}
