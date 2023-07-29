/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/28 20:26:30 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	int	philosophers;		// count of philosophers
	int	die_t;				// life time: time to die
	int	eat_t;				// time to eat
	int	sleep_t;			// time to sleep
	int	must_eat;			// count of must eat -> option! not must arg
}	t_data;

typedef struct s_philo
{
	pthread_t	id;
	int			eat_cnt;
}	t_philo;


#endif
