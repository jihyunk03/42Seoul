/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:32:10 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/27 15:33:57 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*res;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	i = 0;
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	if (size == 0)
		return (res);
	while (i < count * size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
