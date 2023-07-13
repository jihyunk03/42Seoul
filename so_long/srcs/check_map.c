/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:01:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/13 17:57:52 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_parse_map_from_file(int fd, t_maps *new);
static char	*_join_with_line(char *string, char *line);

static void	_check_value_from_map(t_maps *new);
static void	_check_lines(t_maps *new, int idx);
static int	_is_valid_value(t_maps *new, char c, int i);

void	check_map(t_maps *new_maps, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_open(filename);
	_parse_map_from_file(fd, new_maps);
	_check_value_from_map(new_maps);
	check_valid_map(new_maps);
}

static void	_parse_map_from_file(int fd, t_maps *new)
{// map에 마지막이 enter인 경우 따로 다시 고려
	char	*string;
	char	*line;
	char	*tmp;

	string = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)	// condition of breaking loop
			break ;
		if (string == NULL)
			new->width = ft_strlen(line);
		new->height++;
		string = _join_with_line(string, line);
		if (string == NULL)
			error_map(new, "map: is empty!\n");
	}
	new->map = ft_split(string, '\n');
	free (string);
	if (new->map == NULL || new->map[0] == NULL)
		error_map(new, "map: is empty!\n");
	if (new->width < 4 && new->height < 4)	// 유효하지 않은 map, 큰 map도 처리하기
		error_map(new, "map: too small\n");
}

static char	*_join_with_line(char *string, char *line)
{
	char	*new_string;

	if (string == NULL)
		return (line);
	new_string = ft_strjoin(string, line);
	free (string);
	free (line);
	if (new_string == NULL)
		exit (EXIT_FAILURE);	// fail in strjoin
	if (*new_string == 0)
	{
		free (new_string);
		return (NULL);
	}
	return (new_string);
}

static void	_check_value_from_map(t_maps *new)
{// line 별로 개수 및 값을 인지하고 값들이 조건에 맞는지 확인, map 크기 제한 고민
	int	idx;

	idx = 0;
	while (new->map[idx])
	{
		if (ft_strlen(new->map[idx]) != new->width)	// check width
			error_map(new, "map: not equal in width\n");
		_check_lines(new, idx);
		idx++;
	}
	if (idx != new->height)		// check height
		error_map(new, "map: not equal in height\n");
	if (new->p != 1)		// check P == 1
		error_map(new, "map: 'P' must be one\n");
	else if (new->c < 1)	// check C > 0
		error_map(new, "map: 'C' must be at least one\n");
	else if (new->e != 1)	// check E == 1
		error_map(new, "map: 'E' must be one\n");
}

static void	_check_lines(t_maps *new, int idx)
{// 벽으로 둘러쌓여 있는지 확인, P-C-E 개수 저장
	int	i;

	i = 0;
	if (idx == 0 || idx == new->height - 1)
		while (new->map[idx][i])
			if (new->map[idx][i++] != '1')
				error_map(new, "map: not surrounded by walls\n");
	else
		while (new->map[idx][i])
			if (_is_valid_value(new, new->map[idx][i], i++) == FALSE)
				error_map(new, "map: invalid value\n");
}

static int	_is_valid_value(t_maps *new, char c, int i)
{
	if ((i == 0 || i == new->width - 1) && c != '1')
		error_map(new, "map: not surrounded by walls\n");
	if (c == 'P')
		new->p++;
	else if (c == 'C')
		new->c++;
	else if (c == 'E')
		new->e++;
	else if (c != '0' && c != '1')
		return (FALSE);
	return (TRUE);
}
