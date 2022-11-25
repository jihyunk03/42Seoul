/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:39:56 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/12 11:09:57 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	i;
	long long	len;
	int			*res;

	len = (long long)max - (long long)min;
	if (len <= 0)
	{
		*range = 0;
		return (0);
	}
	res = (int *)malloc(sizeof(int) * len);
	if (res == 0)
		return (-1);
	i = 0;
	while (i < len)
	{
		res[i] = min;
		min++;
		i++;
	}
	*range = res;
	return (len);
}
