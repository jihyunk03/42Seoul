/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:03:51 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/11 15:05:14 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_queens(int idx, int val, int *arr)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (val == arr[i])
			return (0);
		if ((i - idx) == (arr[i] - val) || (i - idx) == (val - arr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_arr(int *arr)
{
	int		i;
	char	c;

	i = -1;
	while (++i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	ft_recursive(int idx, int *arr, int *cnt)
{
	int	val;

	if (idx == 10)
	{
		ft_print_arr(arr);
		(*cnt)++;
		return ;
	}
	val = 0;
	while (val < 10)
	{
		if (ft_check_queens(idx, val, arr))
		{
			arr[idx] = val;
			ft_recursive(idx + 1, arr, cnt);
		}
		val++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	cnt;
	int	arr[10];

	cnt = 0;
	ft_recursive(0, arr, &cnt);
	return (cnt);
}
