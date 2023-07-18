/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:30:13 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/18 22:06:36 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_maps	*init_maps(void)
{
	t_maps	*new_maps;

	new_maps = malloc(sizeof(t_maps));
	if (new_maps == NULL)
		exit (EXIT_FAILURE);
	new_maps->map = NULL;
	new_maps->width = 0;
	new_maps->height = 0;
	new_maps->p = 0;
	new_maps->c = 0;
	new_maps->e = 0;
	new_maps->visited = NULL;
	new_maps->x = 0;	// 굳이..?
	new_maps->y = 0;	// same as x
	new_maps->e_flag = FALSE;
	return (new_maps);
}

void	init_visited(t_maps *maps)
{
	int	i;

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

t_game	*init_game(t_maps *maps)
{
	t_game	*new_game;

	new_game = malloc(sizeof(t_game));
	if (new_game == NULL)
		exit (EXIT_FAILURE);
	new_game->mlx = mlx_init();
	new_game->win = mlx_new_window(new_game->mlx, \
					maps->width, maps->height, "Nick's way to Judy");
	return (new_game);
}
