/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:23:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/06 13:13:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a_stack)
{
	a_stack->tail->next = a_stack->head;
	a_stack->head->prev = a_stack->tail;
	a_stack->tail = a_stack->head;
	a_stack->head = a_stack->head->next;
	a_stack->head->prev = NULL;
	a_stack->tail->next = NULL;
}

void	rb(t_stack *b_stack)
{
	b_stack->tail->next = b_stack->head;
	b_stack->head->prev = b_stack->tail;
	b_stack->tail = b_stack->head;
	b_stack->head = b_stack->head->next;
	b_stack->head->prev = NULL;
	b_stack->tail->next = NULL;
}

void	rr(t_stack *a_stack, t_stack *b_stack)
{
	ra(a_stack);
	rb(b_stack);
}
