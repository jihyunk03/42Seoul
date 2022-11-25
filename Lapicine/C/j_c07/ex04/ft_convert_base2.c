/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:59:33 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/12 16:19:35 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
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

int	is_in_base(char c, char *base)
{
	int	idx;

	idx = -1;
	while (base[++idx])
	{
		if (c == base[idx])
			return (idx);
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int count, int *sign)
{
	int	num;
	int	val;

	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			(*sign) *= (-1);
		str++;
	}
	while (1)
	{
		val = is_in_base(*str, base);
		if (val >= 0)
		{
			num = num * count + val;
			str++;
		}
		else
			break ;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base, int *sign)
{
	int	count;

	count = 0;
	while (base[count])
		count++;
	return (ft_atoi(str, base, count, sign));
}
