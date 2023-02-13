/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/13 16:08:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack, int size)
{
	t_dll	*node;
	int		val;

	if (stack->head == NULL || stack->size == 1)
		return (TRUE);
	node = stack->head;
	val = stack->head->idx;
	while (size--)
	{
		if (node->idx != val++)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}
