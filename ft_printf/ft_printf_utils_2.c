/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:43:51 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/01 16:19:47 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(void *ptr, int *len)
{
	*len += write(1, "0x", 2);
	print_base((unsigned long)ptr, "0123456789abcdef", len);
}

void	print_base(unsigned long num, char *charset, int *len)
{
	if (num >= 16)
	{
		print_base(num / 16, charset, len);
		print_base(num % 16, charset, len);
	}
	else
		*len += write(1, &charset[num % 16], 1);
}
