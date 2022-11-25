/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:15:34 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/13 15:17:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	ft_str_count(char **strs, int sep_len, int size)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	count += ((size - 1) * sep_len);
	return (count);
}

void	ft_strcat(char *dest, char *src, int *idx)
{
	int	s_idx;

	s_idx = 0;
	while (src[s_idx])
	{
		*(dest + *idx) = src[s_idx];
		(*idx)++;
		s_idx++;
	}
	*(dest + *idx) = '\0';
}

char	*ft_join(char **strs, char *sep, char *str_ptr, int size)
{
	int	idx;
	int	i;

	idx = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str_ptr, strs[i], &idx);
		i++;
		if (i < size)
			ft_strcat(str_ptr, sep, &idx);
	}
	str_ptr[idx] = '\0';
	return (str_ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		all_len;
	int		sep_len;
	char	*str_ptr;

	if (size == 0)
	{
		str_ptr = (char *)malloc(sizeof(char));
		*str_ptr = 0;
		return (str_ptr);
	}
	sep_len = ft_strlen(sep);
	all_len = ft_str_count(strs, sep_len, size);
	str_ptr = (char *)malloc(sizeof(char) * (all_len + 1));
	if (str_ptr == 0)
		return (0);
	return (ft_join(strs, sep, str_ptr, size));
}
