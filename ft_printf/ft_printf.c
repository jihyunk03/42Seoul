/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:15:48 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/01 12:30:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
			len += check_val(s[++i], &ap);
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

int	check_val(char c, va_list *ap)
{
	int	len;

	len = 0;
	if (c == '%')
		len += write(1, "%%", 1);
	else if (c == 'c')
		print_chr(va_arg(*ap, int), &len);
	else if (c == 's')
		print_str(va_arg(*ap, char *), &len);
	else if (c == 'p')
		print_ptr(va_arg(*ap, void *), &len);
	else if (c == 'd' || c == 'i')
		put_nbr(va_arg(*ap, int), &len);
	else if (c == 'u')
		print_nbr(va_arg(*ap, unsigned int), &len);
	else if (c == 'x')
		print_base(va_arg(*ap, unsigned int), "0123456789abcdef", &len);
	else if (c == 'X')
		print_base(va_arg(*ap, unsigned int), "0123456789ABCDEF", &len);
	return (len);
}
