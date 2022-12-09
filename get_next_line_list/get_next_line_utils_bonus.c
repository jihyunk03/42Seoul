/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:51:49 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/10 04:56:23 by jihykim2         ###   ########.fr       */
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
		while (tmp->next && tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
	free (lst->backup);
	free (lst);
	return (NULL);
}

t_list	*ft_lstnew(int fd_new)
{
	t_list	*t_new;

	t_new = (t_list *)malloc(sizeof(t_list));
	if (t_new == NULL)
		return (NULL);
	t_new->fd = fd_new;
	t_new->backup = (char *)malloc(sizeof(char));
	if (t_new->backup == NULL)
	{
		free (t_new);
		return (NULL);
	}
	t_new->backup[0] = '\0';
	t_new->next = NULL;
	return (t_new);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcpy(res + len1, s2, len2 + 1);
	return (res);
}
