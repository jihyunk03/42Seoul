/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:11:06 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/01 17:08:14 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		check_val(char c, va_list *ap);
void	print_chr(int c, int *len);
void	print_str(char *str, int *len);
void	print_nbr(unsigned int num, int *len);
void	put_nbr(int num, int *len);
void	print_ptr(void *ptr, int *len);
void	print_base(unsigned long num, char *charset, int *len);

#endif
