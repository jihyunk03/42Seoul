/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:16:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/14 14:03:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*decide_command(t_stack *stack, int value);
static void	rotate_for_push(t_stack *b_stack, int cnt);

void	sort_to_a(t_stack *a_stack, t_stack *b_stack)
{
	char	*cmd;

	while (b_stack->size)
	{
		cmd = find_value(b_stack, b_stack->size - 1);
		while (b_stack->head->idx != b_stack->size - 1)
			rotate(b_stack, cmd);
		push(b_stack, a_stack, PA);
	}
}

static char	*decide_command(t_stack *stack, int value)		// RB RRB -> cmd로 구분 불가능!!!!!!!!
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
		return (RB);
	else
		return (RRB);
}

static void	rotate_for_push(t_stack *b_stack, int cnt)
{
	int	i;

	if (cnt < 0)
		i = 1;
	else
		i = -1;
	while (cnt)
	{
		if (i < 0)
			rotate(b_stack, RB);
		else
			rv_rotate(b_stack, RRB);
		cnt += i;
	}
}
