/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:16:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 15:11:36 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	decide_direction(t_stack *stack, int value);

void	b_sort_to_a(t_stack *a_stack, t_stack *b_stack)
{
	int	dir;

	while (b_stack->size)
	{
		dir = decide_direction(b_stack, b_stack->size - 1);
		while (b_stack->head->idx != b_stack->size - 1)
		{
			if (dir > 0)
				rotate(b_stack, RB);
			else
				rv_rotate(b_stack, RRB);
		}
		push(b_stack, a_stack, PA);
	}
}

static int	decide_direction(t_stack *stack, int value)
{
	t_dll	*node;
	int		cnt;

	node = stack->head;
	cnt = 0;
	while (node->idx != value && node)
	{
		node = node->next;
		cnt++;
	}
	if (cnt <= stack->size / 2)
		return (1);
	else
		return (-1);
}
