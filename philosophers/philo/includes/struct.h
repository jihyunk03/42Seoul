/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/22 18:43:19 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"

/* [shared memory] */
typedef struct s_data
{
	int				philosophers;		// num of philosophers
	int				die_t;				// time to die
	int				eat_t;				// time to eat
	int				sleep_t;			// time to sleep
	int				must_eat;			// count of must eat (optional)
	long long		start_t;			// start time
	pthread_mutex_t	*forks;				// mutex for forks
	int				*fork_state;		// forks state: USING, AVAILABLE
	pthread_mutex_t	dead;				// mutex for check dead
	int				someone_dead;		// flag for checking someone dead
	pthread_mutex_t	print;				// mutex for print messages
	int				no_print;			// flag for not printing when someone died
}	t_data;

/* [philo's data] */
typedef struct s_philo
{
	struct s_data	*data;		// pointer for shared data
	pthread_t		tid;		// thread id(each philosopher)
	int				id;			// philosopher's id
	int				left;		// index for left fork(philo's)
	int				right;		// index for rifht fork(next philo's)
	int				eat_cnt;	// count of eating
	long long		last_eat;	// time to start last eating
}	t_philo;

#endif
