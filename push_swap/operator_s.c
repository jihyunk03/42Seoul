/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:52:47 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/06 12:21:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a_stack)
{
	t_dll	*tmp;

	if (a_stack->head == NULL)
		return ;
	tmp = a_stack->head;
	a_stack->head = tmp->next;
	tmp->next = a_stack->head->next;
	tmp->prev = a_stack->head;
	a_stack->head->prev = NULL;
	a_stack->head->next = tmp;

// not use tmp
	// a_stack->head = a_stack->head->next;
	// a_stack->head->prev->next = a_stack->head->next;
	// a_stack->head->prev->prev = a_stack->head;
	// a_stack->head->next = a_stack->head->prev;
	// a_stack->head->prev = NULL;
}

void	sb(t_stack *b_stack)
{
	t_dll	*tmp;

	if (b_stack->head == NULL)
		return ;
	tmp = b_stack->head;
	b_stack->head = tmp->next;
	tmp->next = b_stack->head->next;
	tmp->prev = b_stack->head;
	b_stack->head->prev = NULL;
	b_stack->head->next = tmp;
}

void	ss(t_stack *a_stack, t_stack *b_stack)
{
	sa(a_stack);
	sb(b_stack);
}
