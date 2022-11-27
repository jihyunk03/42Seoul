/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:33 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/27 15:37:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (NULL);
}

static int	ft_arrlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (len);
}

static int	ft_len(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*(s + cnt) && *(s + cnt) != c)
		cnt++;
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int		idx;
	int		str_len;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (ft_arrlen(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			str_len = ft_len(s, c);
			arr[idx] = (char *)malloc(sizeof(char) * (str_len + 1));
			if (arr[idx] == NULL)
				return (ft_free_all(arr, idx));
			ft_strlcpy(arr[idx], s, str_len + 1);
			s += str_len;
			idx++;
		}
		else
			s++;
	}
	arr[idx] = NULL;
	return (arr);
}
