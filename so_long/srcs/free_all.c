/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:11:48 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/13 17:14:52 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_maps(t_maps *maps)
{
	int	i;

	if (maps->map != NULL)
	{
		i = 0;
		while (maps->map[i])
			free (maps->map[i++]);
		free (maps->map);
	}
	free (maps);
}
