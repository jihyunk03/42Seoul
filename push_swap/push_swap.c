/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:23:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/10 14:07:14 by jihykim2         ###   ########.fr       */
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
		exit (0);
	// stack init
	a_stack = stack_init(av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)
	{
		write(1, "Error\n", 6);
		exit (0);
	}

	// push_swap
	// quick_sort(a_stack, b_stack);




	// for memory leaks: atexit
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}

// 1 2 3 4 "1 2 3 4" 5 6 7 8 9
// memory leaks
void	check_leak(void)
{
	system("leaks a.out");
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
