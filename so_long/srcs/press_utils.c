/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 06:57:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 09:15:24 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_identify_values(t_game *game, t_maps *maps);

void	press_w(t_game *game, t_maps *maps)
{
	if (maps->map[maps->y - 1][maps->x] == '1' || \
		(maps->map[maps->y - 1][maps->x] == 'E' && maps->c != 0))
		return ;
	modify_image(game, GROUD, maps->x, maps->y);
	maps->map[maps->y][maps->x] = '0';
	maps->y--;
	maps->move++;
	_identify_values(game, maps);
}

void	press_s(t_game *game, t_maps *maps)
{
	if (maps->map[maps->y + 1][maps->x] == '1' || \
		(maps->map[maps->y + 1][maps->x] == 'E' && maps->c != 0))
		return ;
	modify_image(game, GROUD, maps->x, maps->y);
	maps->map[maps->y][maps->x] = '0';
	maps->y++;
	maps->move++;
	_identify_values(game, maps);
}

void	press_a(t_game *game, t_maps *maps)
{
	if (maps->map[maps->y][maps->x - 1] == '1' || \
		(maps->map[maps->y][maps->x - 1] == 'E' && maps->c != 0))
		return ;
	modify_image(game, GROUD, maps->x, maps->y);
	maps->map[maps->y][maps->x] = '0';
	maps->x--;
	maps->move++;
	_identify_values(game, maps);
}

void	press_d(t_game *game, t_maps *maps)
{
	if (maps->map[maps->y][maps->x + 1] == '1' || \
		(maps->map[maps->y][maps->x + 1] == 'E' && maps->c != 0))
		return ;
	modify_image(game, GROUD, maps->x, maps->y);
	maps->map[maps->y][maps->x] = '0';
	maps->x++;
	maps->move++;
	_identify_values(game, maps);
}

static void	_identify_values(t_game *game, t_maps *maps)
{
	if (maps->map[maps->y][maps->x] == 'E')
	{
		maps->e_flag = TRUE;
		return ;
	}
	else if (maps->map[maps->y][maps->x] == '0')
		modify_image(game, MOVE, maps->x, maps->y);
	else if (maps->map[maps->y][maps->x] == 'C')
	{
		modify_image(game, GET, maps->x, maps->y);
		maps->map[maps->y][maps->x] = '0';
		maps->c--;
	}
	if (maps->c == 0)
		modify_image(game, DONE, maps->end[0], maps->end[1]);
}
