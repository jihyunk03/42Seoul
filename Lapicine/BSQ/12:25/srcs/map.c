/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:05:41 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/15 00:12:09 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_line(char *str, int len)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < len - 3)
	{
		if (str[i] < '0' && str[i] > '9')
			return (-1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	get_info(char *first_line, int first_len, t_map *info)
{
	info->line = get_line(first_line, first_len);
	if (info->line < 0)
		return (0);
	info->empty = first_line[first_len - 3];
	info->obstacle = first_line[first_len - 2];
	info->full = first_line[first_len - 1];
	if (info->empty == info->obstacle || info->empty == info->full
		|| info->obstacle == info->full)
		return (0);
	return (1);
}

int	map_info(char *map_str, t_map *info)
{
	int		first_len;
	int		i;
	char	*first_line;

	i = 0;
	while (map_str[i] && map_str[i] != '\n')
		i++;
	first_len = i;
	if (first_len < 4)
		return (0);
	first_line = (char *)malloc(sizeof(char) * first_len + 1);
	ft_strncpy(first_line, map_str, first_len);
	i++;
	while (map_str[i] && map_str[i] != '\n')
		i++;
	info->col = i - first_len - 1;
	if (info->col <= 0)
		return (free_str(first_line));
	if (get_info(first_line, first_len, info) == 0)
		return (free_str(first_line));
	free(first_line);
	return (1);
}

int	**map_init(t_map info, char **map_str)
{
	int	**result;
	int	i;
	int	j;

	result = (int **)malloc(sizeof(int *) * info.line);
	i = -1;
	while (++i < info.line)
	{
		result[i] = (int *)malloc(sizeof(int) * info.col);
		j = -1;
		while (++j < info.col)
		{
			if (map_str[i + 1][j] == info.empty)
				result[i][j] = 1;
			else if (map_str[i + 1][j] == info.obstacle)
				result[i][j] = 0;
			else
				return (0);
		}
	}
	return (result);
}
