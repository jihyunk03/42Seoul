/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:51:44 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/13 04:21:03 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*lst;
	char			*gnl;
	char			*buff;
	size_t			gnl_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	lst = find_fd(&head, fd);
	if (lst == NULL)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	gnl_len = read_file(&(lst->backup), fd, &buff, check_newline(lst->backup));
	free (buff);
	if (gnl_len == 0 || *(lst->backup) == '\0')
		return (free_all(&head, lst));
	gnl = (char *)malloc(sizeof(char) * (gnl_len + 1));
	if (gnl == NULL)
		return (free_all(&head, lst));
	ft_strlcpy(gnl, lst->backup, gnl_len + 1);
	lst->backup = save_for_next(lst->backup, &gnl, gnl_len);
	if (lst->backup == NULL)
		return (free_all(&head, lst));
	return (gnl);
}

t_list	*find_fd(t_list **head, int fd_new)
{
	t_list	*tmp;

	if (*head == NULL)
	{
		*head = ft_lstnew(fd_new);
		if (*head == NULL)
			return (NULL);
		return (*head);
	}
	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd_new)
			return (tmp);
		if (tmp->next == NULL)
			tmp->next = ft_lstnew(fd_new);
		tmp = tmp->next;
	}
	return (NULL);
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

size_t	read_file(char **backup, int fd, char **buff, size_t gnl_len)
{
	ssize_t	readsize;
	char	*tmp;

	if (*buff == NULL)
		return (0);
	while (gnl_len == 0)
	{
		readsize = read(fd, *buff, BUFFER_SIZE);
		if (readsize == 0)
			break ;
		else if (readsize < 0)
			return (0);
		(*buff)[readsize] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(*backup, *buff);
		free (tmp);
		if (*backup == NULL)
			return (0);
		gnl_len = check_newline(*backup);
	}
	if (gnl_len == 0 && readsize == 0)
		gnl_len = ft_strlen(*backup);
	return (gnl_len);
}

char	*save_for_next(char *backup, char **gnl, size_t gnl_len)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(backup) - gnl_len;
	tmp = backup;
	backup = (char *)malloc(sizeof(char) * (len + 1));
	if (backup == NULL)
	{
		free (*gnl);
		*gnl = NULL;
		free (tmp);
		return (NULL);
	}
	ft_strlcpy(backup, tmp + gnl_len, len + 1);
	free (tmp);
	return (backup);
}
