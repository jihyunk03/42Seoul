/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:28:10 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/27 15:04:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst > src && dst < src + len)
	{
		i = len;
		while (--i >= 0)
		{
			d[i] = s[i];
			if (i == 0)
				break ;
		}
		return (d);
	}
	return (ft_memcpy(dst, src, len));
}
