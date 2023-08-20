/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_print_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:10:25 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 16:18:22 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_message(t_philo *philo, char *message)
{
	sem_wait(philo->print);
	printf("%lld %d %s\n", current_time() - philo->start_t, \
	philo->id, message);
	sem_post(philo->print);
}
