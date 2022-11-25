/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suno <suno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:53:51 by suno              #+#    #+#             */
/*   Updated: 2022/08/27 20:10:08 by suno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putchar_repeat(int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		++i;
	}
}

void	make_raw(int x, char c)
{
	ft_putchar(c);
	if (x > 1)
	{
		++c;
		ft_putchar_repeat(x - 2, c);
		++c;
		ft_putchar(c);
	}
	write(1, "\n", 1);
}

void	make_col(int x, int y, char c)
{
	int	i;

	i = 1;
	while (i < y - 1)
	{
		ft_putchar(c);
		if (x > 1)
		{
			ft_putchar_repeat(x - 2, ' ');
			ft_putchar(c);
		}
		write(1, "\n", 1);
		++i;
	}
}

void	rush(int x, int y)
{
	make_raw(x, 'A');
	if (y > 1)
	{
		make_col(x, y, 'B');
		make_raw(x, 'A');
	}
}
