/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:50 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/27 15:28:41 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_nbr(long ln, int fd)
{
	char	c;

	if (ln)
	{
		c = ln % 10 + '0';
		ft_print_nbr(ln / 10, fd);
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	if (fd < 0)
		return ;
	ln = (long)n;
	if (ln == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	ft_print_nbr(ln, fd);
}
