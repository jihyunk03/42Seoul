/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:41:58 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/07 21:12:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[i] || !base[i + 1])
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_to_base(long nbr, char *base, int count)
{
	if (nbr != 0)
	{
		ft_to_base(nbr / count, base, count);
		write(1, &base[nbr % count], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		count;
	long	lnbr;

	lnbr = (long)nbr;
	if (!check_base(base))
		return ;
	if (lnbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	else if (lnbr < 0)
	{
		write(1, "-", 1);
		lnbr *= (-1);
	}
	count = 0;
	while (base[count])
		count++;
	ft_to_base(lnbr, base, count);
}
