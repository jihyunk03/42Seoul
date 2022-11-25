/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:30:56 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/13 23:44:19 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

#include <unistd.h>

int	val_min(int left, int up, int dia)
{
	int	val;

	val = 0;
	if (!left || !up || !dia)
		return (val);
	else if (dia <= left && dia <= up)
		val = dia;
	else if (up <= dia && up <= left)
		val = up;
	else if (left <= dia && left <= up)
		val = left;
	return (val);
}

void	find_square(int **sq, t_map info, t_max *data)
{
	int	i;
	int	j;

	i = 1;
	data->size = 1;
	while (i < info.line)
	{
		j = 1;
		while (j < info.col)
		{
			if (sq[i][j] == 0)
			{
				j++;
				continue ;
			}
			sq[i][j] = val_min(sq[i][j - 1], sq[i - 1][j], sq[i - 1][j - 1]) + 1;
			if (sq[i][j] > data->size)
			{
				data->size = sq[i][j];
				data->x = i - sq[i][j] + 1;
				data->y = j - sq[i][j] + 1;
			}
			j++;
		}
		i++;
	}
}

void	print_result(int **sq, t_map info, t_max data)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.line)
	{
		j = 0;
		while (j < info.col)
		{
			if (sq[i][j] == 0)
				write(1, &info.obstacle, 1);
			else
			{
				if ((i >= data.x && i <= data.x + data.size - 1)
					&& (j >= data.y && j <= data.y + data.size - 1))
					write(1, &info.full, 1);
				else
					write(1, &info.empty, 1);
			}
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}


int	main(void)
{
	int		**sq;// input array
	t_map	info;
	t_max	data;

	/*info.line = 10;
	info.col = 10;
	info.empty = '.';
	info.obstacle = 'o';
	info.full = 'X';
	// example
	int sq[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};*/

	find_square(sq, info, &data);
	print_result(sq, info, data);
	return (0);
}
