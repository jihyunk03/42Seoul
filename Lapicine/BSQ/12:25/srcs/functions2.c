/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:03:22 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/15 00:03:53 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	free_str(char *str)
{
	free(str);
	return (0);
}

void	free_char(char **str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_int(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	print_err(void)
{
	write(2, "map error\n", 10);
	return (0);
}
