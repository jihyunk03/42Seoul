/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/11 18:33:54 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_DEFINE_H
# define NUMBER_DEFINE_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

enum e_error
{
	NoInt = 0,
	Overflow,
	Duplicated,
	A_alloc,
	B_alloc
}	ERROR;

#endif
