/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:30:13 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/17 17:21:27 by jihykim2         ###   ########.fr       */
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
	return (new_maps);
}
