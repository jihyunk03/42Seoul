/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:07:14 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 18:21:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_size_three(t_stack *stack);
static void	sort_size_four(t_stack *a_stack, t_stack *b_stack);
static void	sort_size_five(t_stack *a_stack, t_stack *b_stack);
static int	where_is_max(t_stack *stack);

void	short_sort(t_stack *a_stack, t_stack *b_stack)
{
	if (check_sort(a_stack, a_stack->size))
		return ;
	if (a_stack->size == 2)
		swap(a_stack, SA);
	else if (a_stack->size == 3)
		sort_size_three(a_stack);
	else if (a_stack->size == 4)
		sort_size_four(a_stack, b_stack);
	else if (a_stack->size == 5)
		sort_size_five(a_stack, b_stack);
}

static void	sort_size_three(t_stack *stack)
{
	int	max;

	max = where_is_max(stack);
	if (max == 1)
		rv_rotate(stack, RRA);
	else if (max == 0 && stack->head->next->idx < stack->tail->idx)
		rotate(stack, RA);
	else
		swap(stack, SA);
	if (check_sort(stack, stack->size) == FALSE)
		sort_size_three(stack);
}

static void	sort_size_four(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->head->next->idx == 0)
		rotate(a_stack, RA);
	else if (a_stack->tail->idx == 0 || a_stack->tail->prev->idx == 0)
		while (a_stack->head->idx != 0)
			rv_rotate(a_stack, RRA);
	push(a_stack, b_stack, PB);
	if (check_sort(a_stack, a_stack->size) == FALSE)
		sort_size_three(a_stack);
	push(b_stack, a_stack, PA);
}

static void	sort_size_five(t_stack *a_stack, t_stack *b_stack)
{
	while (a_stack->size > 3)
	{
		if (a_stack->head->idx < 2)
			push(a_stack, b_stack, PB);
		else
			rotate(a_stack, RA);
	}
	if (check_sort(b_stack, 2) == TRUE)
		swap(b_stack, SB);
	if (check_sort(a_stack, a_stack->size) == FALSE)
		sort_size_three(a_stack);
	push(b_stack, a_stack, PA);
	push(b_stack, a_stack, PA);
}

static int	where_is_max(t_stack *stack)
{
	t_dll	*node;

	node = stack->head;
	if (node->idx > node->next->idx && node->idx > stack->tail->idx)
		return (0);
	else if (node->next->idx > node->idx && node->next->idx > stack->tail->idx)
		return (1);
	else
		return (2);
}
