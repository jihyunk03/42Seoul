/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:51:44 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/17 02:51:09 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*lst;
	char			*buff;
	size_t			gnl_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	lst = find_fd(&head, fd);
	if (lst == NULL)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (free_all(&head, lst));
	gnl_len = read_file(lst, &buff);
	free (buff);
	if (gnl_len == 0 || *(lst->backup) == '\0')
		return (free_all(&head, lst));
	return (cut_next_line(&head, lst, gnl_len));
}

t_list	*find_fd(t_list **head, int fd_new)
{
	t_list	*tmp;

	if (*head == NULL)
		*head = gnl_lstnew(fd_new);
	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd_new)
			return (tmp);
		if (tmp->next == NULL)
			tmp->next = gnl_lstnew(fd_new);
		tmp = tmp->next;
	}
	return (NULL);
}

size_t	read_file(t_list *lst, char **buff)
{
	ssize_t	readsize;
	char	*tmp;

	while (check_newline(lst->backup) == 0)
	{
		readsize = read(lst->fd, *buff, BUFFER_SIZE);
		if (readsize == 0)
			return (ft_strlen(lst->backup));
		else if (readsize < 0)
			return (0);
		(*buff)[readsize] = '\0';
		tmp = lst->backup;
		lst->backup = ft_strjoin(lst->backup, *buff);
		free (tmp);
		if (lst->backup == NULL)
			return (0);
	}
	return (check_newline(lst->backup));
}

size_t	check_newline(char *backup)
{
	size_t	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i++] == '\n')
			return (i);
	}
	return (0);
}

char	*cut_next_line(t_list **head, t_list *lst, size_t gnl_len)
{
	size_t	len;
	char	*gnl;
	char	*tmp;

	gnl = malloc(sizeof(char) * (gnl_len + 1));
	if (gnl == NULL)
		return (free_all(head, lst));
	ft_strlcpy(gnl, lst->backup, gnl_len + 1);
	len = ft_strlen(lst->backup) - gnl_len;
	tmp = lst->backup;
	lst->backup = malloc(sizeof(char) * (len + 1));
	if (lst->backup == NULL)
	{
		free (gnl);
		free (tmp);
		return (free_all(head, lst));
	}
	if (ft_strlcpy(lst->backup, tmp + gnl_len, len + 1) == 0)
		free_all(head, lst);
	free (tmp);
	return (gnl);
}
