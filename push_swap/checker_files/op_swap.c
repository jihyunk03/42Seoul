/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:52:47 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/14 02:48:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap(t_stack *stack);

void	swap(t_stack *stack, char *op)
{
	if (stack->size < 2)
		return ;
	do_swap(stack);
	if (op)
		ft_printf("%s", op);
}

void	swap_both(t_stack *a_stack, t_stack *b_stack, char *op)
{
	if (a_stack->size < 2 && b_stack->size < 2)
		return ;
	do_swap(a_stack);
	do_swap(b_stack);
	if (op)
		ft_printf("%s", op);
}

static void	do_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->idx;
	stack->head->idx = stack->head->next->idx;
	stack->head->next->idx = tmp;
}
