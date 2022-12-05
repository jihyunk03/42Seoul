/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:32:58 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/05 21:57:13 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup; // malloc으로 할당 받아 read한 결과물을 저장해놓는 문자열의 주소
	char		*gnl; // return
	char		buf[BUFFER_SIZE + 1]; // read 한 내용을 해당 버퍼에 담는 것 (null값까지)
	ssize_t		readsize; // read의 반환 값
	ssize_t		nl_idx; // index for newline or end of line(null)
	ssize_t		i; // backup의 index

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nl_idx = -1;
	i = 0;
	gnl = NULL;
	while (nl_idx < 0)
	{
		if (backup == NULL)
			backup = ft_strdup("");
		nl_idx = check_backup(backup);
		if (nl_idx >= 0)
			break ;
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == 0)
			break ;
		else if (readsize < 0)
			return (free_all(&backup));
		else
			buf[readsize] = '\0';
		backup = ft_strjoin(backup, buf);
		if (backup == NULL)
			return (NULL);
	}
	if (readsize == 0 && nl_idx == -1)
		nl_idx = ft_strlen(backup) - 1;
	gnl = (char *)malloc(sizeof(char) * (nl_idx + 2));
	if (gnl == NULL)
		return (free_all(&backup));
	ft_strlcpy(gnl, backup, nl_idx + 2);
	ft_strlcpy(backup, backup + nl_idx + 1, ft_strlen(backup) - nl_idx + 1);
	return (gnl);
}

ssize_t	check_backup(char *backup)
{
	ssize_t	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*free_all(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	return (NULL);
}
