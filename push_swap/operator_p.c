/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:23:07 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/10 13:38:15 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_to_stack(t_stack *stack, t_dll *lst);

void	pa(t_stack *from, t_stack *to)
{
	t_dll	*tmp;

	if (from->size == 0)
		return ;
	tmp = from->head;
	from->head = tmp->next;
	if (from->head == NULL)
		from->tail = NULL;
	else
		from->head->prev = NULL;
	p_to_stack(to, tmp);
	from->size--;
}

void	pb(t_stack *from, t_stack *to)
{
	t_dll	*tmp;

	if (from->size == 0)
		return ;
	tmp = from->head;
	from->head = tmp->next;
	if (from->head == NULL)
		from->tail = NULL;
	else
		from->head->prev = NULL;
	p_to_stack(to, tmp);
	from->size--;
}

static void	p_to_stack(t_stack *stack, t_dll *lst)
{
	if (stack->head == NULL)
	{
		stack->head = lst;
		stack->tail = lst;
		lst->next = NULL;
	}
	else
	{
		stack->head->prev = lst;
		lst->next = stack->head;
		stack->head = lst;
	}
	lst->prev = NULL;
	stack->size++;
}
