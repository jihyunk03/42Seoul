/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:15:48 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/29 15:12:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *s, ...)
{
	va_list ap;
	int		len;

	va_start(ap, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
			len += check_val(++s, ap);
		else
			len += write(1, s, 1);
		s++;
	}
	return (len);
}

int	check_val(char c, va_list ap)
{
	int	len;

	if (c == '%')
		len = write(1, "%%", 1);
	else if (c == 'c')
		len = print_char(va_arg(ap, int));
	else if (c == 's')
	else if (c == 'p')
	else if (c == 'd' || c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (c == 'X')
	else
		return (0);
	return (len);
}
