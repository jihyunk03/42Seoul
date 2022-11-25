/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:42:42 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/05 11:20:35 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		*(dest + index) = *(src + index);
		index++;
	}
	*(dest + index) = '\0';
	return (dest);
}
