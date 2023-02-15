/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rv_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:23:13 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 20:06:50 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_rv_rotate(t_stack *stack);

void	rv_rotate(t_stack *stack, char *op)
{
	if (stack->size < 2)
		return ;
	do_rv_rotate(stack);
	if (op)
		ft_printf("%s", op);
}

void	rv_rotate_both(t_stack *a_stack, t_stack *b_stack, char *op)
{
	if (a_stack->size < 2 && b_stack->size < 2)
		return ;
	do_rv_rotate(a_stack);
	do_rv_rotate(b_stack);
	if (op)
		ft_printf("%s", op);
}

static void	do_rv_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
}
