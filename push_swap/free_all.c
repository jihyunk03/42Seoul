/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:00:38 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/05 20:34:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_stack(t_stack *stack)
{
	t_dll	*node;
	t_dll	*save;

	if (stack == NULL)
		return (NULL);
	node = stack->head;
	while (node)
	{
		save = node->next;
		free (node);
		node = save;
	}
	free (stack);
	return (NULL);
}

void	*free_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
	return (NULL);
}
