/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:15:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 15:43:37 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	decide_direction(t_stack *stack, int value);
static int	init_chunck(int size);

void	a_sort_to_b(t_stack *a_stack, t_stack *b_stack)
{
	int	num;
	int	chunk;
	int	dir;

	num = 0;
	chunk = init_chunck(a_stack->size);
	while (a_stack->size > 0)
	{
		dir = decide_direction(a_stack, num + chunk);
		while (a_stack->head->idx > num + chunk)
		{
			if (dir > 0)
				rotate(a_stack, RA);
			else
				rv_rotate(a_stack, RRA);
		}
		push(a_stack, b_stack, PB);
		if (b_stack->head->idx > num)
			rotate(b_stack, RB);
		num++;
	}
}

static int	decide_direction(t_stack *stack, int value)
{
	t_dll	*node;
	int		cnt;

	node = stack->head;
	cnt = 0;
	while (node->idx > value && node)
	{
		node = node->next;
		cnt++;
	}
	if (cnt <= stack->size / 2)
		return (1);
	else
		return (-1);
}

static int	init_chunck(int size)
{
	int	chunk;

	if (size < 10)
		chunk = 3;
	else if (size < 30)
		chunk = 5;
	else
		chunk = (int)(0.000000053 * size * size + 0.03 * size + 14.5);
	return (chunk);
}
