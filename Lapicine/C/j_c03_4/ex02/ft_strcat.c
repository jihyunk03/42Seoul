/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:43:04 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/01 16:33:56 by jihykim2         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	d_idx;
	int	s_idx;

	d_idx = ft_strlen(dest);
	s_idx = 0;
	while (src[s_idx])
	{
		*(dest + d_idx) = *(src + s_idx);
		d_idx++;
		s_idx++;
	}
	*(dest + d_idx) = '\0';
	return (dest);
}
