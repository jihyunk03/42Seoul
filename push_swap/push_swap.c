/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:23:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 19:25:34 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	// t_error	errorno;

	// check memory leaks
	// atexit(check_leak);
	if (ac < 2)
		return (0);
	a_stack = stack_init(av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)
		return (free_for_exit(a_stack, b_stack, FALSE));
	if (check_sort(a_stack, a_stack->size) == FALSE)
	{
		if (a_stack->size <= 5)
			short_sort(a_stack, b_stack);
		else
		{
			a_sort_to_b(a_stack, b_stack);
			b_sort_to_a(a_stack, b_stack);
		}
	}
	return (free_for_exit(a_stack, b_stack, TRUE));
}

// memory leaks
void	check_leak(void)
{
	system("leaks --quiet push_swap");
}

void	check_operator_result(t_stack *stack, char *op)
{
	t_dll	*node;
	int		i;

	node = stack->head;
	i = 0;
	printf("=====name: %s=====\n", op);
	while (node)
	{
		printf("idx[%d]: %d\n", i++, node->idx);
		node = node->next;
	}
	printf("=====size: %d=====\n\n", stack->size);
}

void	check_stack_idx(t_stack *stack)
{
	t_dll	*node;

	ft_printf("==========\n");
	node = stack->head;
	while (node)
	{
		ft_printf("%d\n", node->idx);
		node = node->next;
	}
	ft_printf("==========\n");
}
