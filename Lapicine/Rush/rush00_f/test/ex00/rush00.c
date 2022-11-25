/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suno <suno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:41:07 by suno              #+#    #+#             */
/*   Updated: 2022/08/27 20:07:02 by suno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_draw(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || (i == y && j == x))
		ft_putchar('o');
	else if ((i == 1 && j == x) || (i == y && j == 1))
		ft_putchar('o');
	else
	{
		if (i == 1 || i == y)
			ft_putchar('-');
		else if (j == 1 || j == x)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i <= y)
	{
		j = 0;
		while (++j <= x)
		{
			ft_draw(x, y, i, j);
		}
		write(1, "\n", 1);
		i++;
	}
}
