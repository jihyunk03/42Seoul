/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:38:14 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/04 21:50:58 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col(int **arr, int **rc, int col, int start)
{
	int	max;
	int	i;
	int	cnt;

	i = start;
	max = 0;
	cnt = 0;
	while (0 <= i && i < 4)
	{
		if (max < arr[i][col])
		{
			max = arr[i][col];
			cnt++;
		}
		if (start == 0)
			i++;
		else
			i--;
	}
	if (start == 0 && cnt == rc[0][col])
		return (1);
	if (start == 3 && cnt == rc[1][col])
		return (1);
	return (0);
}

int	check_row(int **arr, int **rc, int row, int start)
{
	int	max;
	int	i;
	int	cnt;

	i = start;
	max = 0;
	cnt = 0;
	while (0 <= i && i < 4)
	{
		if (max < arr[row][i])
		{
			max = arr[row][i];
			cnt++;
		}
		if (start == 0)
			i++;
		else
			i--;
	}
	if (start == 0 && cnt == rc[2][row])
		return (1);
	if (start == 3 && cnt == rc[3][row])
		return (1);
	return (0);
}

int	check_height(int **arr, int **rc, int idx)
{
	if ((arr[idx / 4][idx % 4] != -1) && (idx % 4 == 3) &&
		((check_row(arr, rc, idx / 4, 0) == 0)
		|| check_row(arr, rc, idx / 4, 3) == 0))
		return (0);
	if ((arr[idx / 4][idx % 4] != -1) && (idx / 4 == 3) &&
		((check_col(arr, rc, idx % 4, 0) == 0)
		|| (check_col(arr, rc, idx % 4, 3) == 0)))
		return (0);
	return (1);
}

int	check_nowhere(int **arr, int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arr[row][i] == value || arr[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}
