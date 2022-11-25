/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:18:29 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/03 15:09:38 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_idx;
	unsigned int	s_idx;
	unsigned int	return_value;

	d_idx = ft_strlen(dest);
	s_idx = 0;
	return_value = ft_strlen(dest) + ft_strlen(src);
	if (size <= d_idx)
		return (size + ft_strlen(src));
	while ((d_idx <= return_value) && (d_idx < size - 1))
	{
		*(dest + d_idx) = *(src + s_idx);
		d_idx++;
		s_idx++;
	}
	*(dest + d_idx) = '\0';
	return (return_value);
}
