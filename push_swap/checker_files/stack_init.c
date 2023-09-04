/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:29:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 20:07:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	index_init(t_stack *stack);

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
		if (push_to_stack(new, data[i]) == FALSE)
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

static void	index_init(t_stack *stack)
{
	t_dll	*find;
	t_dll	*node;
	int		cnt;

	find = stack->head;
	while (find)
	{
		node = stack->head;
		cnt = 0;
		while (node)
		{
			if (find->data > node->data)
				cnt++;
			node = node->next;
		}
		find->idx = cnt;
		find = find->next;
	}
}
