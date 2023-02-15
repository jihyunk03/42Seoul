/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:00:38 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/16 05:05:31 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	free_for_exit(t_stack *a_stack, t_stack *b_stack, int errorno)
{
	free_stack(a_stack);
	free_stack(b_stack);
	if (errorno == FALSE)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

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

int	free_dll(t_dll *lst)
{
	if (lst == NULL)
		return (FALSE);
	free (lst);
	return (FALSE);
}

int	free_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return (FALSE);
	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
	return (FALSE);
}
