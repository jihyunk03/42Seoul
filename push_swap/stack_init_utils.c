/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:59:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/07 00:44:47 by jihykim2         ###   ########.fr       */
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
	if (arr == NULL)
		return (0);
	i = 0;
	flag = 0;
	while (arr[i])
	{
		if (is_integer(arr[i]) == 0)
			return (free_arr(arr));
		lst = new_dll(push_swap_atoi(arr[i++], &flag), flag);
		if (lst == NULL || flag)
			return (free_arr(arr));
		dll_add_back(new, lst);
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
		if (ft_isdigit(*s++) == 0)
			return (0);
	}
	return (1);
}

int	push_swap_atoi(const char *str, int *flag)
{
	long	res;
	int		len;
	int		sign;

	res = 0;
	len = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		if (++len > 10 || res < INT_MIN || res > INT_MAX)
			(*flag)++;
	}
	return (sign * res);
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

int	check_and_init(t_stack *stack)
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
			else if (&(find->data) != &(node->data) && find->data == node->data)
				return (0);
			node = node->next;
		}
		find->idx = cnt;
		find = find->next;
	}
	return (1);
}
