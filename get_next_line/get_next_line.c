/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:32:58 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/04 03:01:54 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	free (s1);
	ft_strlcpy(res + ft_strlen(s1), s2, len + 1);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*backup; // return 값으로 malloc으로 할당 받은 문자열의 주소
	char		buf[BUFFER_SIZE + 1]; // read 한 내용을 해당 버퍼에 담는 것 (null값까지)
	char		*gnl; // newline까지 잘라서 다시 넣는 곳(for join to backup)
	int			readsize; // read의 반환 값
	int			i; // index for newline or end of line(null)

	if (fd > OPEN_MAX)
		return (NULL);
	readsize = read(fd, buf, BUFFER_SIZE);
	while (readsize > 0)
	{
		if (readsize == 0)
			break ;
		buf[readsize] = '\0';
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
				break ;
			i++;
		}
		gnl = (char *)malloc(sizeof(char) * (i + 1));
		if (gnl == NULL)
			return (NULL);
		ft_strlcpy(gnl, buf, i + 1);
		backup = ft_strjoin(backup, gnl);
		ft_strlcpy(buf, buf + i, BUFFER_SIZE - i);
		readsize = read(fd, buf, BUFFER_SIZE);
	}
}



#include <fcntl.h>
#include <unistd.h>

int	main (void)
{
	char	*str;
	int		fd;
	int		len;

	while (str)
	{
		fd = open("./text.txt", O_RDONLY);
		str = get_next_line(fd);
		if (str == NULL)
		{
			free (str);
			return (0);
		}
		len = ft_strlen(str);
		write(fd, str, len);
		free (str);
	}
	return (0);
}
