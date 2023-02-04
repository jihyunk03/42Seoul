/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:29:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/03 20:50:40 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(char **data)
{
	t_stack	*new;
	int		i;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	if (data == NULL)
	{
		new->head = NULL;
		new->end = NULL;
		return (new);
	}
	while (*data)
	{
		i = ft_atoi(*data);
	}
}

t_dll	*new_dll(int data)
{
	t_dll	*new;

	new = malloc(sizeof(t_dll));
	if (new == NULL)
		exit (1);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

