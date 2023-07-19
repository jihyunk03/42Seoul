/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 04:02:42 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 05:20:12 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_init_images(t_game *game);
static void	_put_image_to_map(t_game *game, t_maps *maps);

t_game	*init_game(t_maps *maps)
{
	t_game	*new_game;
	int	width;
	int	height;

	new_game = malloc(sizeof(t_game));
	if (new_game == NULL)
		exit (EXIT_FAILURE);
	new_game->mlx = mlx_init();
	new_game->win = mlx_new_window(new_game->mlx, \
					maps->width * 64, maps->height * 64, "Nick's way to Judy");
	new_game->img_Grass = mlx_xpm_file_to_image(new_game->mlx, "../images/Grass.xpm", &width, &height);
	printf("void *: %p\n", new_game->img_Grass);
	// _init_images(new_game);
	// _put_image_to_map(new_game, maps);
	printf("====\n");
	return (new_game);
}

static void	_init_images(t_game *game)
{
	int	width;
	int	height;

	game->img_Grass = mlx_xpm_file_to_image(game->mlx, \
					"../images/Grass.xpm", &width, &height);
	game->img_Wall = mlx_xpm_file_to_image(game->mlx, \
					"../images/Wall.xpm", &width, &height);
	game->img_Nick = mlx_xpm_file_to_image(game->mlx, \
					"../images/Nick.xpm", &width, &height);
	game->img_Bluederry = mlx_xpm_file_to_image(game->mlx, \
					"../images/Blueberry.xpm", &width, &height);
	game->img_Judy_OK = mlx_xpm_file_to_image(game->mlx, \
					"../images/Judy_OK.xpm", &width, &height);
	game->img_Judy_NO = mlx_xpm_file_to_image(game->mlx, \
					"../images/Judy_NO.xpm", &width, &height);
}

static void	_put_image_to_map(t_game *game, t_maps *maps)
{
	int	x;
	int	y;

	printf("void *: %p\n", game->img_Bluederry);
	mlx_put_image_to_window(game->mlx, game->win, \
			game->img_Grass, 0, 0);
	// y = -1;
	// while (++y < maps->height)
	// {
	// 	x = -1;
	// 	while (++x < maps->width)
	// 	{
	// 		mlx_put_image_to_window(game->mlx, game->win, \
	// 		game->img_Grass, x * 64, y * 64);
	// 		printf("=============\n");
	// 		if (maps->map[y][x] == '1')
	// 			mlx_put_image_to_window(game->mlx, game->win, \
	// 			game->img_Wall, x * 64, y * 64);
	// 		else if (maps->map[y][x] == 'C')
	// 			mlx_put_image_to_window(game->mlx, game->win, \
	// 			game->img_Bluederry, x * 64, y * 64);
	// 		else if (maps->map[y][x] == 'P')
	// 			mlx_put_image_to_window(game->mlx, game->win, \
	// 			game->img_Nick, x * 64, y * 64);
	// 		else if (maps->map[y][x] == 'E')
	// 			mlx_put_image_to_window(game->mlx, game->win, \
	// 			game->img_Judy_NO, x * 64, y * 64);
	// 	}
	// }
}
