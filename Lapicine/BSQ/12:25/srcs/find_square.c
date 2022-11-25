/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:13:14 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/15 00:15:55 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int left, int up, int dia)
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

void	reset_info(int **sq, t_map info, t_max *data)
{
	int	i;

	data->size = 0;
	data->x = 0;
	data->y = 0;
	i = -1;
	while (++i < info.col)
	{
		if (sq[0][i] > 0)
		{
			data->size = sq[0][i];
			data->y = i;
			return ;
		}
	}
	i = -1;
	while (++i < info.line)
	{
		if (sq[i][0] > 0)
		{
			data->size = sq[i][0];
			data->x = i;
			return ;
		}
	}
}

void	find_square(int **sq, t_map info, t_max *data)
{
	int	i;
	int	j;

	i = 0;
	reset_info(sq, info, data);
	while (++i < info.line)
	{
		j = 1;
		while (j < info.col)
		{
			if (sq[i][j] == 0)
			{
				j++;
				continue ;
			}
			sq[i][j] = min(sq[i][j - 1], sq[i - 1][j], sq[i - 1][j - 1]) + 1;
			if (sq[i][j] > data->size)
			{
				data->size = sq[i][j];
				data->x = i - sq[i][j] + 1;
				data->y = j - sq[i][j] + 1;
			}
			j++;
		}
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
