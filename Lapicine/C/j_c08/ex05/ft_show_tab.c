/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:44:20 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/15 17:30:03 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, str + idx, 1);
		idx++;
	}
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while (par[idx])
	{
		ft_putnbr(par[idx].size);
		write(1, "\n", 1);
		ft_putstr(par[idx].str);
		write(1, "\n", 1);
		ft_putstr(par[idx].copy);
		write(1, "\n", 1);
	}
}
