/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:59:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/14 12:13:53 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_stack(t_stack *new, char *data)
{
	t_dll	*lst;
	int		i;
	int		flag;
	char	**arr;

	arr = ft_split(data, ' ');
	if (arr == NULL || arr[0] == NULL)
		return (free_arr(arr));
	i = 0;
	flag = TRUE;
	while (arr[i])
	{
		if (is_integer(arr[i]) == FALSE)
			return (free_arr(arr));
		lst = new_dll(push_swap_atoi(arr[i++], &flag), flag);
		if (lst == NULL)
			return (free_arr(arr));
		if (dll_add_back(new, lst) == FALSE)
			return (free_arr(arr));
	}
	free_arr(arr);
	return (1);
}

int	is_integer(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s++) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	push_swap_atoi(const char *str, int *flag)
{
	long	res;
	int		len;
	int		sign;

	res = 0;
	len = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		if (++len >= 10 && (res < INT_MIN || res > INT_MAX))
			*flag = FALSE;
	}
	if (len == 0)
		*flag = FALSE;
	return (sign * res);
}

int	dll_add_back(t_stack *new, t_dll *lst)
{
	t_dll	*node;

	node = new->head;
	while (node)
	{
		if (lst->data == node->data)
			return (free_dll(lst));
		node = node->next;
	}
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
	return (TRUE);
}

void	index_init(t_stack *stack)
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
