/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:03:15 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/15 00:03:17 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	count_line(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			count++;
			while (str[i] && str[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		j;
	int		arr_index;

	arr = (char **)malloc(sizeof(char *) * (count_line(str) + 1));
	arr_index = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			j = i;
			while (str[j] && str[j] != '\n')
				j++;
			arr[arr_index] = (char *)malloc(sizeof(char) * (j - i) + 1);
			ft_strncpy(arr[arr_index++], &str[i], j - i);
			i = j;
		}
		else
			i++;
	}
	arr[arr_index] = 0;
	return (arr);
}
