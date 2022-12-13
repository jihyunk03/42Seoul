/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:32:58 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/13 19:56:30 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	size_t		gnl_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (backup == NULL)
		backup = ft_strdup("");
	if (backup == NULL)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	gnl_len = read_file(&backup, fd, &buff);
	free (buff);
	if (gnl_len == 0 || *backup == '\0')
		return (free_all(&backup));
	return (cut_next_line(&backup, gnl_len));
}

char	*cut_next_line(char **backup, size_t gnl_len)
{
	size_t	len;
	char	*gnl;
	char	*tmp;

	gnl = malloc(sizeof(char) * (gnl_len + 1));
	if (gnl == NULL)
		return (free_all(backup));
	ft_strlcpy(gnl, *backup, gnl_len + 1);
	len = ft_strlen(*backup) - gnl_len;
	tmp = *backup;
	*backup = malloc(sizeof(char) * (len + 1));
	if (*backup == NULL)
	{
		free (tmp);
		return (free_all(&gnl));
	}
	ft_strlcpy(*backup, tmp + gnl_len, len + 1);
	free (tmp);
	return (gnl);
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

size_t	read_file(char **backup, int fd, char **buff)
{
	ssize_t	readsize;
	char	*tmp;

	if (*buff == NULL)
		return (0);
	while (check_newline(*backup) == 0)
	{
		readsize = read(fd, *buff, BUFFER_SIZE);
		if (readsize == 0)
			return (ft_strlen(*backup));
		else if (readsize < 0)
			return (0);
		(*buff)[readsize] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(*backup, *buff);
		free (tmp);
		if (*backup == NULL)
			return (0);
	}
	return (check_newline(*backup));
}
/*
char	*save_for_next(char *backup, size_t gnl_len)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(backup) - gnl_len;
	tmp = backup;
	backup = malloc(sizeof(char) * (len + 1));
	if (backup == NULL)
		return (free_all(&tmp));
	ft_strlcpy(backup, tmp + gnl_len, len + 1);
	free (tmp);
	return (backup);
}
*/
