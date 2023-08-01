/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/01 17:29:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_philo
{
	struct s_data	*data;		// data for philos -> [shared memory]
	pthread_t		tid;		// thread id
	int				id;			// 1 ~ num_id of philosphers(orders)
	int				eat_cnt;	// option!
}	t_philo;

typedef struct s_data	// [shared memory]
{
	int				philosophers;		// count of philosophers
	int				die_t;				// life time: time to die
	int				eat_t;				// time to eat
	int				sleep_t;			// time to sleep
	int				must_eat;			// count of must eat -> option! not must arg
	int				*fork;
	pthread_mutex_t	*f_state;
	pthread_mutex_t	time;
	pthread_mutex_t	die_philo;		// 굳이?
	pthread_mutex_t	end_philo;		// 굳이?
}	t_data;

#endif
