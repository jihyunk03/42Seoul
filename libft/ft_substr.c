/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:26:38 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/27 16:16:20 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;

	if (start > ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, (char *)s + start, size + 1);
	return (res);
}
