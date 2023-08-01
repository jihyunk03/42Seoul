/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/31 17:22:31 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	int				philosophers;		// count of philosophers
	int				die_t;				// life time: time to die
	int				eat_t;				// time to eat
	int				sleep_t;			// time to sleep
	int				must_eat;			// count of must eat -> option! not must arg
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philo
{
	pthread_t	tid;		// thread id
	int			id;			// 1 ~ num_id of philosphers(orders)
	int			eat_cnt;	// option!
}	t_philo;


#endif
