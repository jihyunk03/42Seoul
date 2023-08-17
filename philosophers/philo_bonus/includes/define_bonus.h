/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:10:59 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/17 20:21:44 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_BONUS_H
# define DEFINE_BONUS_H

# define TRUE		1
# define FALSE		0
# define USING		1
# define AVAILABLE	0
# define CONTINUE	1
# define END		0

enum	e_errno
{
	SUCCESS,
	ALLOC_FAIL,
	ARG_ERR,
	MUTEX_ERR,
	PHILO_ERR
};

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"died"


#endif
