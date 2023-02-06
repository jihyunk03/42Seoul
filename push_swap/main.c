/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:09 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/07 01:15:08 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	atexit(check_leak);		// check memory leaks
	if (ac == 1)
		exit (0);
	a_stack = stack_init(av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)	// 더 수정할 것(error 처리)
	{
		write(1, "Error\n", 6);
		free_stack(a_stack);
		free_stack(b_stack);
		return (0);
	}

	// test for stack input
	t_dll	*node = a_stack->head;
	int		i = 0;
	while (av[i])
		printf("%s\n", av[i++]);
	printf("\n");
	while (node)
	{
		printf("%d\n", node->idx);
		node = node->next;
	}

	// for memory leaks: atexit
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}

// 1 2 3 4 "1 2 3 4" 5 6 7 8 9
// memory leaks
void check_leak(void)
{
    system("leaks a.out");
}
