/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suno <suno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:35:23 by suno              #+#    #+#             */
/*   Updated: 2022/08/27 15:14:08 by suno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	normalcase(int x, int y, int i, int j)
{
	while (i <= y)
	{
		while (j <= x)
		{
			if ((i == 1 && j == 1) || (i == y && j == x))
				ft_putchar('A');
			else if ((i == 1 && j == x) || (i == y && j == 1))
				ft_putchar('C');
			else
			{
				if ((i == 1 || i == y) || (j == 1 || j == x))
					ft_putchar('B');
				else
					ft_putchar(' ');
			}
			j++;
		}
		j = 1;
		write(1, "\n", 1);
		i++;
	}
}

void	if_x1(int y)
{
	int	num;

	num = 1;
	ft_putchar('A');
	write(1, "\n", 1);
	while (num <= y - 2)
	{
		ft_putchar('B');
		write(1, "\n", 1);
		num++;
	}
	ft_putchar('C');
	write(1, "\n", 1);
}

void	if_y1(int x)
{
	int	num;

	num = 1;
	ft_putchar('A');
	while (num <= x - 2)
	{
		ft_putchar('B');
		num++;
	}
	ft_putchar('C');
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (x == 1 && y > 1)
		if_x1(y);
	else if (y == 1 && x > 1)
		if_y1(x);
	else
		normalcase(x, y, i, j);
}
