/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:23:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/13 02:12:41 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	// check memory leaks
	// atexit(check_leak);
	if (ac == 1)
		return (0);
	// stack init
	a_stack = stack_init(av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)
	{
		write(1, "Error\n", 6);
		exit (1);
	}

	// push_swap
	// if (a_stack->size < 6)
	// 	short_sort(a_stack, b_stack);
	// else
	// {
	// 	sort_to_b(a_stack, b_stack);
	// 	sort_to_a(a_stack, b_stack);
	// }
	sort_to_b(a_stack, b_stack);
	sort_to_a(a_stack, b_stack);

	// check stack is sorted
	// ft_printf("stack sorted: %d\n", check_sort(a_stack, a_stack->size));
	// ft_printf("a_stack->head->idx: %d\n", a_stack->head->idx);
	// ft_printf("b_stack->size: %d\n", b_stack->size);

	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}

// 1 2 3 4 "1 2 3 4" 5 6 7 8 9
// memory leaks
void	check_leak(void)
{
	system("leaks push_swap");
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
