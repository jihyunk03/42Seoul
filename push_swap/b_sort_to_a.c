/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:16:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/11 18:28:52 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_a(t_stack *a_stack, t_stack *b_stack)
{
	int	cnt;

	while (b_stack->size)
	{
		cnt = find_value(b_stack, b_stack->size - 1);
		rotate_for_push(b_stack, cnt);
		pb(b_stack, a_stack);
	}
}

int	find_value(t_stack *stack, int value)
{
	t_dll	*node;
	int		cnt1;
	int		cnt2;

	node = stack->head;
	cnt1 = 0;
	while (node->idx != value && node)
	{
		cnt1++;
		node = node->next;
	}
	node = stack->tail;
	cnt2 = -1;
	while (node->idx != value && node)
	{
		cnt2--;
		node = node->prev;
	}
	if (cnt1 <= -cnt2)
		return (cnt1);
	else
		return (cnt2);
}

void	rotate_for_push(t_stack *stack, int cnt)
{
	int	i;

	if (cnt < 0)
		i = 1;
	else
		i = -1;
	while (cnt)
	{
		if (i < 0)
			rb(stack);
		else
			rrb(stack);
		cnt += i;
	}
}
