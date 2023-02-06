/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:23:07 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/06 12:34:56 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *from, t_stack *to)
{
	t_dll	*tmp;

	if (from->head == NULL)
		return ;
	tmp = from->head;
	from->head = tmp->next;
	from->head->prev = NULL;
	to->head->prev = tmp;
	tmp->next = to->head;
	tmp->prev = NULL;
	to->head = tmp;
}

void	pb(t_stack *from, t_stack *to)
{
	t_dll	*tmp;

	if (from->head == NULL)
		return ;
	tmp = from->head;
	from->head = tmp->next;
	from->head->prev = NULL;
	to->head->prev = tmp;
	tmp->next = to->head;
	tmp->prev = NULL;
	to->head = tmp;
}
