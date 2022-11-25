/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:04:09 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 12:05:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && src[index])
	{
		*(dest + index) = *(src + index);
		index++;
	}
	while (index < n)
	{
		*(dest + index) = '\0';
		index++;
	}
	return (dest);
}
