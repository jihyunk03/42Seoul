/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:21:35 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/07 21:05:25 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_lnb(long lnb)
{
	int	num;

	num = 0;
	if (lnb != 0)
	{
		num = lnb % 10 + '0';
		put_lnb(lnb / 10);
		write(1, &num, 1);
	}
}

void	ft_putnbr(int nb)
{
	long	lnb;

	lnb = (long)nb;
	if (lnb < 0)
	{
		lnb *= (-1);
		write(1, "-", 1);
	}
	if (lnb == 0)
		write(1, "0", 1);
	else
		put_lnb(lnb);
}
