/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:28:10 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/30 14:18:06 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst > src && dst < src + len)
	{
		while (--len >= 0)
		{
			d[len] = s[len];
			if (len == 0)
				break ;
		}
		return (d);
	}
	return (ft_memcpy(dst, src, len));
}
