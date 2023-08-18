/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:07:47 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 15:01:54 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "./header_bonus.h"

typedef struct s_data	// [shared memory]
{
	int				philosophers;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				must_eat;
	long long		start_t;
	int				print_flag;		// for check dead for stop printing
	pthread_mutex_t	*forks;
	int				*fork_state;
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
