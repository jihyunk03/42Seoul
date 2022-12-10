/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:32:58 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/11 05:11:03 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*gnl;
	size_t		gnl_len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (free_all(&backup));
	if (backup == NULL)
		backup = ft_strdup("");
	if (backup == NULL)
		return (NULL);
	gnl_len = read_file(&backup, fd, check_newline(backup));
	if (gnl_len == 0 || *backup == '\0')
		return (free_all(&backup));
	gnl = (char *)malloc(sizeof(char) * (gnl_len + 1));
	if (gnl == NULL)
		return (free_all(&backup));
	ft_strlcpy(gnl, backup, gnl_len + 1);
	backup = restore_backup(backup, gnl_len);
	if (backup == NULL)
		return (free_all(&gnl));
	return (gnl);
}

size_t	check_newline(char *backup)
{
	size_t	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	read_file(char **backup, int fd, size_t gnl_len)
{
	ssize_t	readsize;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];

	readsize = 0;
	while (gnl_len == 0)
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == 0)
			break ;
		else if (readsize < 0)
			return (0);
		buf[readsize] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(*backup, buf);
		free (tmp);
		if (*backup == NULL)
			return (0);
		gnl_len = check_newline(*backup);
	}
	if (readsize == 0 && gnl_len == 0)
		gnl_len = ft_strlen(*backup);
	return (gnl_len);
}

char	*restore_backup(char *backup, size_t gnl_len)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(backup) - gnl_len;
	tmp = backup;
	backup = (char *)malloc(sizeof(char) * (len + 1));
	if (backup == NULL)
		return (free_all(&tmp));
	ft_strlcpy(backup, tmp + gnl_len, len + 1);
	free_all (&tmp);
	return (backup);
}

void	*free_all(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}
