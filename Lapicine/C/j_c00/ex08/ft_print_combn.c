/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:08:10 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/10 21:27:24 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive(int n, int idx, char *arr)
{
	int	val;

	if (idx == n)
	{
		write(1, arr, n);
		if (arr[0] == 10 - n + '0')
			return ;
		else
			write(1, ", ", 2);
		return ;
	}
	val = arr[idx - 1] + 1 - '0';
	while (val <= 9)
	{
		arr[idx] = val + '0';
		ft_recursive(n, idx + 1, arr);
		val++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	arr[10];

	i = 0;
	while (i <= 10 - n)
	{
		arr[0] = i + '0';
		ft_recursive(n, 1, arr);
		i++;
	}
}

int	main(int ac, char *av[])
{
	(void)ac;
	ft_print_combn(av[1][0] - '0');
	return (0);
}
