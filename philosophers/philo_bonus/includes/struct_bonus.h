/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:52 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 21:56:01 by jihykim2         ###   ########.fr       */
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
	sem_t		*print;
	pid_t		*child_id;		// 부모에서 판단할 자식 아이디들 -> 자식에서 free

	// in child process: philo's data
	pthread_t	monitor;
	int			id;
	char		*philo_id;		// philo마다 생성된 semaphore의 이름(id)
	sem_t		*data_lock;
	int			eat_cnt;
	long long	last_eat;
}	t_philo;

#endif
