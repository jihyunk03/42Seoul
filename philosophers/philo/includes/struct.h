/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/08 18:41:48 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_philo
{
	struct s_data	*data;		// data for philos -> [shared memory]
	pthread_t		tid;		// thread id
	int				id;			// 0 ~ num_id - 1 of philosphers(orders)
	int				left;
	int				right;
	int				eat_cnt;	// option!
	long long		last_eat_time;
}	t_philo;

typedef struct s_data	// [shared memory]
{
	int				philosophers;		// count of philosophers
	int				die_t;				// life time: time to die
	int				eat_t;				// time to eat
	int				sleep_t;			// time to sleep
	int				must_eat;			// count of must eat -> option! not must arg
	int				*forks;
	pthread_mutex_t	*f_state;
	pthread_mutex_t	print;			// mutex for printing messages
	pthread_mutex_t	end_philo;		// 굳이? -> 이건 그닥,,ㅋ (full_philo)
	pthread_mutex_t	die_philo;		// 굳이? -> 응 필요해~ someone_die 보호할거야
	int				someone_die;
}	t_data;

#endif
