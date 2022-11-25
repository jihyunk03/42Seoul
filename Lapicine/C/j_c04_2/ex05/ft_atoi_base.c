/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:36:15 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/07 17:57:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (1);
	}
	return (0);
}

int	idx_base(char c, char *base)
{
	int	idx;

	idx = -1;
	while (base[++idx])
	{
		if (c == base[idx])
			return (idx);
	}
	return (idx);
}

int	ft_atoi(char *str, char *base, int count)
{
	int	idx;
	int	sign;
	int	num;

	idx = 0;
	sign = 1;
	num = 0;
	while (str[idx] == 32 || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	while (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign *= (-1);
		idx++;
	}
	while (is_in_base(str[idx], base))
	{
		num = num * count + idx_base(str[idx], base);
		idx++;
	}
	return (sign * num);
}	

int	ft_atoi_base(char *str, char *base)
{
	int	count;

	if (!check_base(base))
		return (0);
	count = 0;
	while (base[count])
		count++;
	return (ft_atoi(str, base, count));
}
