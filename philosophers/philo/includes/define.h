/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:42:44 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/09 09:16:48 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define TRUE	1
# define FALSE	0

# define NO_ALLOC	0	// system error
# define SUCCESS	1
# define ARG_ERR	2
# define MUTEX_ERR	3
# define PHILO_ERR	4

# define PHILO_END	5	// option 만족 시 끝내기
# define PHILO_DEAD	6

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"died"

#endif
