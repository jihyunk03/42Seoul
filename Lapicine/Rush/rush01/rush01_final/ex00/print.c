/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:39:00 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/04 22:06:07 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**ft_malloc(int row, int col)
{
	int	i;
	int	**arr;

	i = 0;
	arr = (int **)malloc(sizeof(int *) * row);
	while (i < col)
	{
		arr[i] = (int *)malloc(sizeof(int) * col);
		i++;
	}
	return (arr);
}

void	ft_free(int **arr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	**split(char *str, int **rc)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			rc[i][j] = *str - '0';
			str += 2;
			j++;
		}
		i++;
	}
	return (rc);
}

void	ft_print1(int **arr, int *count)
{
	int	i;

	i = 0;
	if (*count == 0)
	{
		while (i < 16)
		{
			arr[i / 4][i % 4] += '0';
			write(1, &arr[i / 4][i % 4], 1);
			i++;
			if (i % 4 != 0)
				write(1, " ", 1);
			if (i != 15 && (i % 4 == 0))
			{
				write(1, "\n", 1);
			}
		}
	}
}

int	is_error(int argc, char *arg_str)
{
	int	idx;
	int	ok;

	idx = 0;
	ok = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (arg_str[idx])
	{
		if ((idx % 2 == 0) && (arg_str[idx] >= '1' && arg_str[idx] <= '4'))
			ok++;
		else if (idx % 2 && (arg_str[idx] == ' '))
			ok++;
		idx++;
	}
	if (idx != 31 || ok != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
