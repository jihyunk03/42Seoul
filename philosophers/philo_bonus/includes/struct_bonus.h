/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:52 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/22 17:23:51 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "./header_bonus.h"

typedef struct s_philo
{
	/* [shared data] */
	int			philosophers;		// num of philosophers
	int			die_t;				// time to die
	int			eat_t;				// time to eat
	int			sleep_t;			// time to sleep
	int			must_eat;			// count of must eat (optional)
	long long	start_t;			// start time
	sem_t		*forks;				// semaphore for forks
	sem_t		*print;				// semaphore for print
	pid_t		*child_id;			// process id(each philosopher's)
	/* [philo's data] */
	int			id;				// philosopher's id
	char		*philo_id;		// string for philo's id -> semaphore open
	sem_t		*data_lock;		// semaphore for monitoring dead
	int			eat_cnt;		// count of eating
	long long	last_eat;		// time to start last eating
}	t_philo;

#endif
