/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:36:10 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/28 13:34:35 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_chr(int c, int *len)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	*len = write(1, &uc, 1);
}

void	print_str(char *s, int *len)
{
	if (s == NULL)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (*s)
		*len += write(1, s++, 1);
}

void	print_ptr(void *p, int *len)
{
	*len += write(1, "0x", 2);
	print_base((unsigned long)p, "0123456789abcdef", 16, len);
}

void	print_nbr(int n, int *len)
{
	unsigned int	ui;

	ui = (unsigned int)n;
	if (n < 0)
	{
		ui *= -1;
		*len += write(1, "-", 1);
	}
	print_base(ui, "0123456789", 10, len);
}

void	print_base(unsigned long n, char *set, unsigned int setlen, int *len)
{
	if (n >= setlen)
	{
		print_base(n / setlen, set, setlen, len);
		print_base(n % setlen, set, setlen, len);
	}
	else
		*len += write(1, &set[n % setlen], 1);
}
