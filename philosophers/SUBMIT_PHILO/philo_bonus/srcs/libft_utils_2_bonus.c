/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:30:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 17:32:21 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int	ft_numlen(long ln);

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (sign * res);
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
