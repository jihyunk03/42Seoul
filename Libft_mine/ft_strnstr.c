/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:31:03 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/27 16:02:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	n_len;
	char	*res;

	idx = 0;
	n_len = ft_strlen(needle);
	res = (char *)haystack;
	if (n_len == 0)
		return (res);
	while (res[idx] && idx < len)
	{
		if (idx + n_len <= len && ft_strncmp(&res[idx], needle, n_len) == 0)
			return (&res[idx]);
		idx++;
	}
	return (0);
}
