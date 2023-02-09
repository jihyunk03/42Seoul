/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/09 20:48:40 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack, int size)
{
	t_dll	*node;
	int		val;

	if (stack->head == NULL || stack->size == 1)
		return (1);		// 스택이 비어있거나 1개인 경우 종료(true 로 종료)
	node = stack->head;
	val = stack->head->idx;
	while (size--)
	{
		if (node->idx != val++)
			return (0);
		node = node->next;
	}
	return (1);
}
