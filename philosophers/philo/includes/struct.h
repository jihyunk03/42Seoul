/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:43:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/11 18:39:35 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"
/* Questions */
/*
 * 1. forks를 보호하라고 subject에 명시되어 있는데 forks를 뮤텍스로 사용하는 것 자체가
      같은 의미 아닌가? -> 임계구역 자체에 접근이 불가능한데 해당 fork 값으로 출력이나 다른 행동을 하는 것도 아니고..
 * 2. print_message()의 위치 -> 해당 행동을 시작하자마자 출력하는 형식으로 진행했는데 괜춘??
 * 3. time에 대한 변수도 뮤텍스로 보호해주어야 하는가? ... 굳이 생각해보면 해야할 것 같은데... 또 아닌것 같기도 ..
*/

typedef struct s_philo
{
	struct s_data	*data;		// data for philos -> [shared memory]
	pthread_t		tid;		// thread id
	int				id;			// 0 ~ num_id - 1 of philosphers(orders)
	int				left;
	int				right;
	int				eat_cnt;	// option!
	long long		last_eat;
	// int				full;
}	t_philo;

typedef struct s_data	// [shared memory]
{
	int				philosophers;		// count of philosophers
	int				die_t;				// life time: time to die
	int				eat_t;				// time to eat
	int				sleep_t;			// time to sleep
	int				must_eat;			// count of must eat -> option! not must arg
	long long		start_t;
	pthread_mutex_t	*f_state;
	int				*forks;
	// pthread_mutex_t	end_philo;		// 굳이? -> 이건 그닥,,ㅋ (full_philo) 필요한듯?
	// int				end;
	pthread_mutex_t	dead_philo;		// 굳이? -> 응 필요해~ dead 보호할거야
	int				dead;
	pthread_mutex_t	print;			// mutex for printing messages
}	t_data;

#endif
