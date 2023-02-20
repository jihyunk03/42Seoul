/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:35:35 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/28 13:32:55 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		find_type(char c, va_list *ap);

void	print_chr(int c, int *len);
void	print_str(char *s, int *len);
void	print_ptr(void *p, int *len);
void	print_nbr(int n, int *len);
void	print_base(unsigned long n, char *set, unsigned int setlen, int *len);

#endif
