/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/12 21:41:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_DEFINE_H
# define NUMBER_DEFINE_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

enum e_error
{
	NoInt = 0,
	Overflow,
	Duplicated,
	A_alloc,
	B_alloc
}	ERROR;

#endif
