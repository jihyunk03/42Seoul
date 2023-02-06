/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:29:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/07 01:14:20 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(char **data)
{
	t_stack	*new;
	int		i;

	new = new_stack();
	if (new == NULL)
		return (NULL);
	i = 0;
	while (data[++i])
	{
		if (push_to_stack(new, data[i]) == 0)
			return (free_stack(new));
	}
	index_init(new);
	return (new);
}

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

t_dll	*new_dll(int data, int flag)
{
	t_dll	*new;

	if (flag)
		return (NULL);
	new = malloc(sizeof(t_dll));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
