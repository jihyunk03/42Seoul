/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/14 12:17:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_ENUM_H
# define DEFINE_ENUM_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define TRUE 1
# define FALSE 0

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define NOPRINT NULL

typedef enum s_error
{
	NOERROR = 0,
	NoInt,
	Overflow,
	Duplicated,
	A_alloc,
	B_alloc
}	t_error;

#endif
