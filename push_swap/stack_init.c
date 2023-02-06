/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:29:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/06 18:07:20 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(char **data)
{
	t_stack	*new;
	t_dll	*lst;
	int		i;

	new = new_stack();
	if (new == NULL)
		return (NULL);
	i = 0;
	while (data[++i])
	{
		if (push_to_stack(new, data[i]) == 0)
			return (NULL);
	}
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

t_dll	*new_dll(int data)
{
	t_dll	*new;

	new = malloc(sizeof(t_dll));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int	push_to_stack(t_stack *new, char *data)
{
	t_dll	*lst;
	int		i;
	char	**arr;

	arr = ft_split(data, ' ');
	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i])
	{
		lst = new_dll(ft_atoi(arr[i++]));
		if (lst == NULL)
			return (free_arr(arr));
		dll_add_back(new, lst);
	}
	free_arr(arr);
	return (1)
}

void	dll_add_back(t_stack *new, t_dll *lst)
{
	if (new->head == NULL)
	{
		new->head = lst;
		new->tail = lst;
	}
	else
	{
		new->tail->next = lst;
		lst->prev = new->tail;
		new->tail = lst;
	}
	new->size++;
}

