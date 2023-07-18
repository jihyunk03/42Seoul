/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:11:48 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/18 17:25:23 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_maps(t_maps *maps)
{
	int	i;

	i = 0;
	free_map(maps->map);
	free_visited(maps);
	free (maps);
}

void	free_visited(t_maps *maps)
{
	int	i;

	if (maps->visited == NULL)
		return ;
	i = 0;
	while (i < maps->height)
		free (maps->visited[i++]);
	free (maps->visited);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
		free (map[i++]);
	free (map);
}
