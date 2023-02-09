/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:14:11 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/09 22:15:07 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_all(t_list **head, t_list *lst)
{
	t_list	*tmp;

	if (*head == NULL || lst == NULL)
		return (NULL);
	tmp = *head;
	if (tmp == lst)
		*head = lst->next;
	else
	{
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
	free (lst->buff);
	free (lst);
	return (NULL);
}

t_list	*gnl_lstnew(int new_fd)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->fd = new_fd;
	lst->buff = malloc(sizeof(char) * (DEFAULT_SIZE + 1));
	if (lst->buff == NULL)
	{
		free (lst);
		return (NULL);
	}
	lst->buff[0] = '\0';
	lst->len = 0;
	lst->b_size = DEFAULT_SIZE;
	lst->next = NULL;
	return (lst);
}

size_t	check_newline(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '\n')
			return (i);
	}
	return (0);
}

char	*realloc_backup(t_list *lst)
{
	char	*tmp;

	tmp = lst->buff;
	while (lst->len + BUFFER_SIZE > lst->b_size)
		lst->b_size *= 2;
	lst->buff = malloc(sizeof(char) * (lst->b_size + 1));
	if (lst->buff == NULL)
	{
		free (tmp);
		return (NULL);
	}
	gnl_strlcpy(lst->buff, tmp, lst->len + 1);
	free (tmp);
	return (lst->buff);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
