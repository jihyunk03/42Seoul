/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:49:03 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/27 15:34:44 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long ln)
{
	int		len;

	len = 0;
	if (ln < 0)
	{
		ln *= -1;
		len++;
	}
	else if (ln == 0)
		return (1);
	while (ln)
	{
		ln /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	ln;
	char	*num;

	ln = (long)n;
	len = ft_numlen(ln);
	if (ln < 0)
		ln *= -1;
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (NULL);
	num[len] = '\0';
	while (--len >= 0)
	{
		num[len] = ln % 10 + '0';
		ln /= 10;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}
