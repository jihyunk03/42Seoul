/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:29:00 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/04 21:06:36 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

typedef struct s_dll
{
	int				data;
	struct s_dll	*prev;
	struct s_dll	*next;
}	t_dll;

typedef struct s_stack
{
	t_dll	*head;
	t_dll	*tail;
}	t_stack;

#endif
