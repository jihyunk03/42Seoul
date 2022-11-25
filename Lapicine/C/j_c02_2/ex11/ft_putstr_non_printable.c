/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:54:06 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 17:53:25 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	d_to_hex(unsigned char c)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= ' ' && str[idx] <= '~')
			write(1, str + idx, 1);
		else
			d_to_hex((unsigned char)str[idx]);
		idx++;
	}
}
