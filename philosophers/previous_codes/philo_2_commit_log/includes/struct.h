/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 15:08:42 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"

typedef struct s_philo
{
	struct s_data	*data;		// data for philos -> [shared memory]
	pthread_t		tid;		// thread id
	int				id;			// 1 ~ num of philosphers(orders)
	int				left;
	int				right;
	int				eat_cnt;	// option !
	long long		last_eat;
}	t_philo;

typedef struct s_data	// [shared memory]
{
	int				philosophers;		// count of philosophers
	int				die_t;				// life time: time to die
	int				eat_t;				// time to eat
	int				sleep_t;			// time to sleep
	int				must_eat;			// count of must eat -> option! default: -1
	long long		start_t;
	pthread_mutex_t	*forks;			// fork의 상태를 따로 보호해주어야 함
	int				*fork_state;
	pthread_mutex_t	dead;
	int				someone_dead;
	pthread_mutex_t	print;
}	t_data;

#endif
