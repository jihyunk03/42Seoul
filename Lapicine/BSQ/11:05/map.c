#include "bsq.h"

int	get_line(char *str, int len)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < len - 3)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	identical_char(t_map info)
{
	if (info.empty == info.obstacle || info.empty == info.full
		|| info.obstacle == info.full)
		return (1);
	return (0);
}

void	get_info(char *first_line, int first_len, t_map *info)
{
	info->line = get_line(first_line, first_len);
	info->empty = first_line[first_len - 3];
	info->obstacle = first_line[first_len - 2];
	info->full = first_line[first_len - 1];
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
	if (first_line == 0)
		return (0);
	ft_strncpy(first_line, map_str, first_len);
	i++;
	while (map_str[i] && map_str[i] != '\n')
		i++;
	info->col = i - first_len - 1;
	if (info->col <= 0)
		return (0);
	get_info(first_line, first_len, info);
	free(first_line);
	if (identical_char(*info))
		return (0);
	return (1);
}

int	**map_init(t_map info, char **map_str)
{
	int	**result;
	int	i;
	int	j;

	result = (int **)malloc(sizeof(int *) * info.line);
	if (result == 0)
		return (0);
	i = -1;
	while (++i < info.line)
	{
		result[i] = (int *)malloc(sizeof(int) * info.col);
		if (result[i] == 0)
			return (0);
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
