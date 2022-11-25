/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:38:44 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/04 22:00:41 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_nowhere(int **arr, int row, int col, int value);
int		check_height(int **arr, int **rc, int idx);
void	ft_print1(int **arr, int *count);
int		is_error(int argc, char *arg_str);
int		**ft_malloc(int row, int col);
void	ft_free(int **arr);
int		**split(char *str, int **rc);

void	recursive_putvalid(int **arr, int **rc, int idx, int *count)
{
	int	i;

	i = 0;
	while (++i <= 4)
	{
		if (check_nowhere(arr, idx / 4, idx % 4, i))
			arr[idx / 4][idx % 4] = i;
		else
			continue ;
		if (!check_height(arr, rc, idx))
		{
			arr[idx / 4][idx % 4] = -1;
			continue ;
		}
		if (idx < 15)
			recursive_putvalid(arr, rc, idx + 1, count);
		else
		{
			ft_print1(arr, count);
			*count = 1;
		}
		arr[idx / 4][idx % 4] = -1;
	}
}

int	main(int argc, char **argv)
{
	int	**rc;
	int	**arr;
	int	idx;
	int	count;

	count = 0;
	if (!is_error(argc, argv[1]))
		return (0);
	idx = -1;
	rc = ft_malloc(4, 4);
	arr = ft_malloc(4, 4);
	while (++idx < 16)
		arr[idx / 4][idx % 4] = -1;
	rc = split(argv[1], rc);
	recursive_putvalid(arr, rc, 0, &count);
	if (count != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_free(arr);
	ft_free(rc);
	return (0);
}
