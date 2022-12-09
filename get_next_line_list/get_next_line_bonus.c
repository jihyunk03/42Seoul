/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:51:44 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/10 03:57:30 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*lst;
	char			*gnl;
	ssize_t			gnl_len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	lst = find_fd(&head, fd);
	if (lst == NULL)
		return (NULL);
	gnl_len = read_file(&(lst->backup), fd, check_newline(lst->backup));
	if (gnl_len < 0 || *(lst->backup) == '\0')
		return (free_all(&head, lst));
	gnl = (char *)malloc(sizeof(char) * (gnl_len + 1));
	if (gnl == NULL)
		return (free_all(&head, lst));
	ft_strlcpy(gnl, lst->backup, gnl_len + 1);
	lst->backup = restore_backup(lst->backup, gnl_len);
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

ssize_t	check_newline(char *backup)
{
	ssize_t	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

ssize_t	read_file(char **backup, int fd, ssize_t gnl_len)
{
	ssize_t	readsize;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];

	readsize = 0;
	while (gnl_len < 0)
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == 0)
			break ;
		else if (readsize < 0)
			return (-1);
		buf[readsize] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(*backup, buf);
		free (tmp);
		if (*backup == NULL)
			return (-1);
		gnl_len = check_newline(*backup);
	}
	if (readsize == 0 && gnl_len == -1)
		gnl_len = ft_strlen(*backup);
	return (gnl_len);
}

char	*restore_backup(char *backup, ssize_t gnl_len)
{
	ssize_t	len;
	char	*tmp;

	len = 0;
	len = ft_strlen(backup) - gnl_len;
	tmp = backup;
	backup = (char *)malloc(sizeof(char) * (len + 1));
	if (backup == NULL)
	{
		free (tmp);
		return (NULL);
	}
	ft_strlcpy(backup, tmp + gnl_len, len + 1);
	free (tmp);
	return (backup);
}
