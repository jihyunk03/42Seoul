/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:07:24 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/03 18:58:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	d_idx;
	unsigned int	s_idx;

	d_idx = ft_strlen(dest);
	s_idx = 0;
	while (src[s_idx] && s_idx < nb)
	{
		*(dest + d_idx) = *(src + s_idx);
		d_idx++;
		s_idx++;
	}
	*(dest + d_idx) = '\0';
	return (dest);
}
