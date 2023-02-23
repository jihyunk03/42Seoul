/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:35:02 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/28 13:05:37 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
			len += find_type(*(++str), &ap);
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (len);
}

int	find_type(char c, va_list *ap)
{
	int	len;

	len = 0;
	if (c == '%')
		len += write(1, "%", 1);
	else if (c == 'c')
		print_chr(va_arg(*ap, int), &len);
	else if (c == 's')
		print_str(va_arg(*ap, char *), &len);
	else if (c == 'p')
		print_ptr(va_arg(*ap, void *), &len);
	else if (c == 'd' || c == 'i')
		print_nbr(va_arg(*ap, int), &len);
	else if (c == 'u')
		print_base(va_arg(*ap, unsigned int), "0123456789", 10, &len);
	else if (c == 'x')
		print_base(va_arg(*ap, unsigned int), "0123456789abcdef", 16, &len);
	else if (c == 'X')
		print_base(va_arg(*ap, unsigned int), "0123456789ABCDEF", 16, &len);
	return (len);
}
