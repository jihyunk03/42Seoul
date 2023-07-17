/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:49:44 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/17 23:07:17 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_init_visited(t_maps *maps);
static void	_dfs(t_maps *maps, int x, int y, int *cnt);

void	check_valid_map(t_maps *maps)
{
	int	**visited;
	int	cnt;

	_init_visited(maps);
	cnt = 0;
	_dfs(maps, maps->x, maps->y, &cnt);
	printf("----colleted c: %d----\n", cnt);
	if (cnt != maps->c || maps->flag == FALSE)
		error_map(maps, "map: no valid path on the map\n");
}

static void	_init_visited(t_maps *maps)
{
	int	i;

	maps->flag = FALSE;
	maps->visited = malloc(sizeof(int *) * maps->height);
	if (maps->visited == NULL)
		exit (EXIT_FAILURE);
	i = 0;
	while (i < maps->height)
	{
		maps->visited[i] = calloc(maps->width, sizeof(int));
		if (maps->visited[i] == NULL)
			exit (EXIT_FAILURE);
		i++;
	}
}

static void	_dfs(t_maps *maps, int x, int y, int *cnt)
{
	if (maps->map[y][x] == '1' || maps->visited[y][x] == TRUE)
		return ;
	// else
	// 	maps->visited[y][x] = TRUE;
	if (maps->map[y][x] == 'C')
	{
		(*cnt)++;
		maps->visited[y][x] = TRUE;
	}
	else if (maps->map[y][x] == 'E' && *cnt == maps->c)
	{
		maps->flag = TRUE;
		return ;
	}
	else if (maps->map[y][x] != 'E')
		maps->visited[y][x] = TRUE;
	_dfs(maps, x + 1, y, cnt);
	_dfs(maps, x, y + 1, cnt);
	_dfs(maps, x - 1, y, cnt);
	_dfs(maps, x, y - 1, cnt);
	// return (FALSE);
}
