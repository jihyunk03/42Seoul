/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:01:24 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 13:01:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	count;

	idx = 0;
	count = 0;
	while (src[count])
		count++;
	if (size == 0)
		return (count);
	while ((idx < size - 1) && src[idx])
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	*(dest + idx) = '\0';
	return (count);
}
