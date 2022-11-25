/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:52:45 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/12 11:52:36 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	len;
	int			*res;

	len = (long long)max - (long long)min;
	if (len <= 0)
		return (0);
	res = (int *)malloc(sizeof(int) * len);
	if (res == 0)
		return (0);
	while (--len >= 0)
		res[len] = --max;
	return (res);
}
