/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:04:06 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/15 01:42:16 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

void	ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	ft_strcpy(ptr, src);
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char *av[])
{
	int			idx;
	int			cnt;
	t_stock_str	*res;

	idx = 0;
	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == 0)
		return (0);
	res[ac] = 0;
	while (++idx < ac)
	{
		(res + idx)->size = ft_strlen(av[idx]);
		(res + idx)->str = av[idx];
		(res + idx)->copy = ft_strdup(av[idx]);
	}
	return (res);
}
