/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:01:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/17 23:02:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_check_value_from_map(t_maps *maps);
static void	_check_lines(t_maps *maps, int idx);
static int	_is_valid_value(t_maps *maps, char c, int x, int y);

void	check_map(t_maps *maps)
{
	int	i;

	i = 0;
	maps->width = ft_strlen(maps->map[0]);
	while (maps->map[i++])
		maps->height++;
	if (maps->width < 4 && maps->height < 4)	// 유효하지 않은 map, 큰 map도 처리하기
		error_map(maps, "map: too small\n");
	_check_value_from_map(maps);
	check_valid_map(maps);
}

static void	_check_value_from_map(t_maps *maps)
{// line 별로 개수 및 값을 인지하고 값들이 조건에 맞는지 확인, map 크기 제한 고민
	int	idx;

	idx = 0;
	while (maps->map[idx])
	{
		if (ft_strlen(maps->map[idx]) != maps->width)	// check width
			error_map(maps, "map: not equal in width\n");
		_check_lines(maps, idx);
		idx++;
	}
	// if (idx != maps->height)		// check height
	// 	error_map(maps, "map: not equal in height\n");
	if (maps->p != 1)		// check P == 1
		error_map(maps, "map: 'P' must be one\n");
	else if (maps->c < 1)	// check C > 0
		error_map(maps, "map: 'C' must be at least one\n");
	else if (maps->e != 1)	// check E == 1
		error_map(maps, "map: 'E' must be one\n");
}

static void	_check_lines(t_maps *maps, int idx)
{// 벽으로 둘러쌓여 있는지 확인, P-C-E 개수 저장
	int	i;

	i = -1;
	if (idx == 0 || idx == maps->height - 1)
	{
		while (maps->map[idx][++i])
			if (maps->map[idx][i] != '1')
				error_map(maps, "map: must be surrounded by walls\n");
	}
	else
		while (maps->map[idx][++i])
			if (_is_valid_value(maps, maps->map[idx][i], i, idx) == FALSE)
				error_map(maps, "map: invalid value\n");
}

static int	_is_valid_value(t_maps *maps, char c, int x, int y)
{
	if ((x == 0 || x == maps->width - 1) && c != '1')
		error_map(maps, "map: must be surrounded by walls\n");
	if (c == 'P')
	{
		maps->p++;
		maps->x = x;
		maps->y = y;
	}
	else if (c == 'C')
		maps->c++;
	else if (c == 'E')
		maps->e++;
	else if (c != '0' && c != '1')
		return (FALSE);
	return (TRUE);
}
