/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:11:48 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 09:33:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_visited(t_maps *maps)
{
	int	i;

	if (maps->visited == NULL)
		return ;
	i = 0;
	while (i < maps->height)
		free (maps->visited[i++]);
	free (maps->visited);
	maps->visited = NULL;
}

void	free_map(t_maps *maps)
{
	int	i;

	if (maps->map == NULL)
		return ;
	i = 0;
	while (maps->map[i])
		free (maps->map[i++]);
	free (maps->map);
	maps->map = NULL;
}

void	free_vars(t_vars *vars)
{
	if (vars == NULL)
		return ;
	free (vars->game);
	free_map(vars->maps);
	free (vars->maps);
	free (vars);
}
