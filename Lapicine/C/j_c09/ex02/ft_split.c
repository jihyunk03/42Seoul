/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:55:17 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/15 17:55:25 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	len_s(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] && !is_charset(str[cnt], charset))
		cnt++;
	return (cnt);
}

int	ft_arr_len(char *str, char *charset)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		if (!is_charset(str[idx], charset))
		{
			cnt++;
			while (!is_charset(str[idx], charset) && str[idx])
				idx++;
		}
		else
			idx++;
	}
	return (cnt);
}

char	**ft_malloc_arr(char *str, char *set, char **ft_s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!is_charset(str[i], set))
		{
			k = 0;
			ft_s[j] = (char *)malloc(sizeof(char) * (len_s(str + i, set) + 1));
			while (!is_charset(str[i], set) && str[i])
			{
				ft_s[j][k] = str[i];
				i++;
				k++;
			}
			ft_s[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	return (ft_s);
}

char	**ft_split(char *str, char *charset)
{
	int		arr_count;
	char	**ft_str;

	arr_count = ft_arr_len(str, charset);
	ft_str = (char **)malloc(sizeof(char *) * (arr_count + 1));
	if (ft_str == 0)
		return (0);
	ft_str[arr_count] = 0;
	ft_str = ft_malloc_arr(str, charset, ft_str);
	return (ft_str);
}
