/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:31:52 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 09:39:42 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	_key_press(int *keycode, t_vars *vars);
static void	_exit_game(t_vars *vars, char *message);

void	play_game(t_maps *maps)
{
	t_game	*game;
	t_vars	*vars;

	game = init_game(maps);
	vars = init_vars(game, vars);
	mlx_key_hook(vars->game->win, key_press, vars);
	mlx_hook(vars->game->win, KEY_EXIT, 0, exit_game, vars);
	mlx_loop(game->mlx);
}

static int	_key_press(int *keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		press_w(vars->game, vars->maps);
	else if (keycode == KEY_S)
		press_s(vars->game, vars->maps);
	else if (keycode == KEY_A)
		press_a(vars->game, vars->maps);
	else if (keycode == KEY_D)
		press_d(vars->game, vars->maps);
	else if (keycode == KEY_ESC)
		exit_game(vars);
	if (vars->maps->e_flag == TRUE)
		exit_game(vars);
	return (0);
}

static void	_exit_game(t_vars *vars, int mode)
{
	mlx_destroy_image(vars->game->img_Grass);
	mlx_destroy_image(vars->game->img_Wall);
	mlx_destroy_image(vars->game->img_Nick);
	mlx_destroy_image(vars->game->img_Bluederry);
	mlx_destroy_image(vars->game->img_Judy_OK);
	mlx_destroy_image(vars->game->img_Judy_NO);
	mlx_destroy_window(vars->game->mlx, vars->game->win);
	if (mode == TRUE)
		ft_printf("Game is Over!! The total number of moves is %d\n", \
					vars->maps->move);
	else
		ft_printf("You give up the game...\n");
	free_vars(vars);
	exit (EXIT_SUCCESS);
}
