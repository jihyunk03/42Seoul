/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:52 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 21:57:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "./header_bonus.h"

typedef struct s_philo
{
	// shared data
	int			philosophers;
	int			die_t;
	int			eat_t;
	int			sleep_t;
	int			must_eat;
	long long	start_t;
	sem_t		*forks;
	int			fork_count;
	sem_t		*print;
	int			no_print;
	pid_t		*child_id;

	// in child process: philo's data
	pthread_t	monitor;
	int			id;
	int			eat_cnt;
	sem_t		*philo_time;
	char		*philo_name;		// philo마다 생성된 semaphore의 이름(id)
	long long	last_eat;
}	t_philo;


#endif
