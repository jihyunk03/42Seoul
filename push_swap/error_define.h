/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/07 15:38:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_DEFINE_H
# define ERROR_DEFINE_H

typedef enum Error
{
	NoInt = 0,
	Overflow,
	Duplicated,
	A_alloc,
	B_alloc
}	ERROR;

#endif
