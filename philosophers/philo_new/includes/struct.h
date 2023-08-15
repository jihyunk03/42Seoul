/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/15 16:21:13 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"

typedef struct s_data	// [shared memory]
{
	int				philosophers;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				must_eat;
	long long		start_t;
	pthread_mutex_t	*f_state;
	int				*forks;
	pthread_mutex_t	dead_philo;
	int				dead;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		tid;
	int				id;
	int				left;
	int				right;
	int				eat_cnt;
	long long		last_eat;
}	t_philo;

#endif
