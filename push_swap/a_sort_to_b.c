/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:15:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/11 18:55:44 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_b(t_stack *a_stack, t_stack *b_stack)
{
	int	num;
	int	chunk;

	num = 0;
	chunk = init_chunck(a_stack->size);
	while (a_stack->size > 0)
	{
		a_to_b(a_stack, b_stack, num++, chunk);
		// if (is_in_stack(b_stack, num))		// 원래는 이 방법이 아님(내가 추가)
		// 	num++;
	}
}

void	a_to_b(t_stack *a_stack, t_stack *b_stack, int num, int chunk)
{
	while (a_stack->head->idx > num + chunk)
		ra(a_stack);
	if (a_stack->head->idx < num)
		pb(a_stack, b_stack);
	else
	{
		pb(a_stack, b_stack);
		rb(a_stack);
	}
}

int	init_chunck(int size)
{
	int	chunk;

	chunk = (int)(0.000000053 * size * size + 0.03 * size + 14.5);
	ft_printf("[ chunk: %d ]\n", chunk);
	return (chunk);
}

int	is_in_stack(t_stack *stack, int num)
{
	t_dll	*node;

	node = stack->head;
	while (node)
	{
		if (num == node->idx)
			return (1);
		node = node->next;
	}
	return (0);
}
