/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:51:44 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/08 21:46:21 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX + 1];
	char		*gnl;
	ssize_t		gnl_len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (backup[fd] == NULL)
		backup[fd] = ft_strdup("");
	if (backup[fd] == NULL)
		return (NULL);
	gnl_len = read_file(&backup[fd], fd, check_newline(backup[fd]));
	if (gnl_len < 0 || ft_strlen(backup[fd]) == 0)
		return (free_all(&backup[fd]));
	gnl = (char *)malloc(sizeof(char) * (gnl_len + 1));
	if (gnl == NULL)
		return (free_all(&backup[fd]));
	ft_strlcpy(gnl, backup[fd], gnl_len + 1);
	backup[fd] = restore_backup(backup[fd], gnl_len);
	if (backup[fd] == NULL)
		return (free_all(&gnl));
	return (gnl);
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
	int		readsize;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];

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
	int		len;
	char	*tmp;

	len = ft_strlen(backup) - gnl_len;
	tmp = backup;
	backup = (char *)malloc(sizeof(char) * (len + 1));
	if (backup == NULL)
		return (free_all(&tmp));
	ft_strlcpy(backup, tmp + gnl_len, len + 1);
	free (tmp);
	return (backup);
}

char	*free_all(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main (void)
{
	int		fd[3];

	fd[0] = open("main.txt", O_RDONLY);
//	fd[1] = open("no_newline.txt", O_RDONLY);
//	fd[2] = open("no_empty.txt", O_RDONLY);

	printf("1. %d: %s", fd[0], get_next_line(fd[0]));
	printf("2. %d: %s", fd[0], get_next_line(fd[0]));
	close(fd[0]);

	printf("\n");
	fd[0] = open("main.txt", O_RDONLY);
	printf("1. %d: %s", fd[0], get_next_line(fd[0]));
	printf("2. %d: %s", fd[0], get_next_line(fd[0]));
	printf("3. %d: %s", fd[0], get_next_line(fd[0]));

	close (fd[0]);
	return (0);
}
*/
