/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:48:36 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 22:43:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
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
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	return (sign * num);
}
