/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:59 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 20:41:49 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_BONUS_H
# define DEFINE_BONUS_H

# define TRUE		1
# define FALSE		0

enum	e_errno
{
	EAT_END = 0,
	ALLOC_FAIL = 250,
	ARG_ERR,
	SEM_ERR,
	THREAD_ERR,
	FORK_ERR
};

# define FORK_SEM	"./forks"
# define PRINT_SEM	"./print"

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"died"


#endif
