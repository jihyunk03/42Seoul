/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:29:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/05 04:21:40 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int len, char **data)
{
	t_stack	*new;
	t_dll	*lst;
	int		i;	// index for (before split)av

	new = new_stack();
	if (new == NULL)
		return (NULL);
	i = 0;
	while (++i < len)
	{
		lst = new_dll(ft_atoi(data[len]));
		if (lst == NULL)
			return (NULL);
		if (new->head == NULL)
		{
			new->head = lst;
			new->tail = lst;
		}
		else
		{
			new->tail->next = lst;
			lst->prev = new->tail;
		}
		new->tail = new->tail->next;
	}
	return (new);
}

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

t_dll	*new_dll(int data)
{
	t_dll	*new;

	new = malloc(sizeof(t_dll));
	if (new == NULL)
		return (NULL);	// exit(error) or return (NULL)
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
/*
t_dll	*dll_add_back(t_dll *end, t_dll *lst)
{
	end->next = lst;
	lst->prev = end;
}
*/
