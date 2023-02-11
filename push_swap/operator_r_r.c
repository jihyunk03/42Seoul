/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:23:13 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/11 16:08:25 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a_stack)
{
	if (a_stack->size < 2)
		return ;
	a_stack->tail->next = a_stack->head;
	a_stack->head->prev = a_stack->tail;
	a_stack->head = a_stack->tail;
	a_stack->tail = a_stack->tail->prev;
	a_stack->head->prev = NULL;
	a_stack->tail->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b_stack)
{
	if (b_stack->size < 2)
		return ;
	b_stack->tail->next = b_stack->head;
	b_stack->head->prev = b_stack->tail;
	b_stack->head = b_stack->tail;
	b_stack->tail = b_stack->tail->prev;
	b_stack->head->prev = NULL;
	b_stack->tail->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	rra(a_stack);
	rrb(b_stack);
	write(1, "rrr\n", 4);
}
