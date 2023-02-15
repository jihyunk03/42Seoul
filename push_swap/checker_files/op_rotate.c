/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:23:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/14 02:50:07 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_stack *stack);

void	rotate(t_stack *stack, char *op)
{
	if (stack->size < 2)
		return ;
	do_rotate(stack);
	if (op)
		ft_printf("%s", op);
}

void	rotate_both(t_stack *a_stack, t_stack *b_stack, char *op)
{
	if (a_stack->size < 2 && b_stack->size < 2)
		return ;
	do_rotate(a_stack);
	do_rotate(b_stack);
	if (op)
		ft_printf("%s", op);
}

static void	do_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->tail = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
}
