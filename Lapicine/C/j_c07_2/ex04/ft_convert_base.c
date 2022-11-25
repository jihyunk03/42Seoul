/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:59:23 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/12 18:43:57 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);
int	is_in_base(char c, char *base);
int	ft_atoi(char *str, char *base, int count);
int	ft_atoi_base(char *str, char *base, int *sign);

int	ft_nbr_len(int nbr, int count, int sign)
{
	int	val;
	int	len;

	val = nbr;
	len = 0;
	if (nbr == 0)
		len++;
	if (sign < 0 && nbr != 0)
		len++;
	while (val > 0)
	{
		val /= count;
		len++;
	}
	return (len);
}

char	*ft_to_base(int nbr, char *base, int count, char *nbr_base)
{
	int	i;
	int	sign;

	sign = 1;
	if (nbr < 0)
	{
		nbr_base[0] = '-';
		nbr *= -1;
		sign = -1;
	}
	i = ft_nbr_len(nbr, count, sign) - 1;
	nbr_base[i + 1] = '\0';
	if (nbr == 0)
		nbr_base[0] = base[0];
	while (nbr > 0)
	{
		nbr_base[i] = base[nbr % count];
		nbr /= count;
		i--;
	}
	return (nbr_base);
}

char	*ft_putnbr_base(int nbr, char *base, int sign)
{
	int		count;
	int		nbr_len;
	char	*nbr_base;

	count = 0;
	while (base[count])
		count++;
	nbr_len = ft_nbr_len(nbr, count, sign);
	nbr_base = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (nbr_len == 0)
		return (0);
	if (nbr == 0)
		return (ft_to_base(0, base, count, nbr_base));
	return (ft_to_base(nbr * sign, base, count, nbr_base));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*res;
	int		sign;

	sign = 1;
	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	number = ft_atoi_base(nbr, base_from, &sign);
	res = ft_putnbr_base(number, base_to, sign);
	if (res == 0)
		return (0);
	return (res);
}
