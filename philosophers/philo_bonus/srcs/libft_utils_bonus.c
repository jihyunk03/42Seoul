/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:10:05 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 18:10:06 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*res;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)s;
	while (i < n)
		res[i++] = 0;
}
