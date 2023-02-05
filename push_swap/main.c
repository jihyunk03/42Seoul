/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:09 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/05 23:16:22 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**arr;	// result of split av

	atexit(check_leak);		// check memory leaks
	if (ac == 1)
		exit (0);
	arr = split_av(ac, av);
	a_stack = stack_init(ac, av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)
		exit (1);
}

// 1 2 3 4 "1 2 3 4" 5 6 7 8 9
// memory leaks
void check_leak(void)
{
     system("leaks a.out");
}
