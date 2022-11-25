/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:31:03 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/23 15:08:51 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	idx;
	char	*res;

	idx = 0;
	res = (char *)haystack;
	if (*needle == '\0')
		return (res);
	while (res[idx] && idx < len)
	{
		if (res[idx] == needle[0])
		{
			i = 0;
			while (needle[i] && idx + i < len && res[idx + i] == needle[i])
				i++;
			if (!needle[i])
				return (&res[idx]);
		}
		idx++;
	}
	return (0);
}
