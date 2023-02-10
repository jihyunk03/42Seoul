/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:15:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/10 13:59:39 by jihykim2         ###   ########.fr       */
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
		a_to_b(a_stack, b_stack, num, chunk);
		if (is_in_stack(b_stack, num))
			num++;
		ft_printf("size: %d\n", a_stack->size);		// remove
	}
}

void	a_to_b(t_stack *a_stack, t_stack *b_stack, int num, int chunk)
{
	while (a_stack->head->idx > num + chunk)
	{
		ra(a_stack);
		write(1, "ra\n", 3);
	}
	if (a_stack->head->idx < num)
	{
		pb(a_stack, b_stack);
		write(1, "pb\n", 3);
	}
	else
	{
		pb(a_stack, b_stack);
		write(1, "pb\n", 3);
		rb(a_stack);
		write(1, "rb\n", 3);
	}
}

int	init_chunck(int size)
{
	if (size < 100)
		return (15);
	else if (size < 500)
		return (30);
	else if (size < 1000)
		return (45);
	else if (size < 2000)
		return (65);
	else
		return (150);
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
