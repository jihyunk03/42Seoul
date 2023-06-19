/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:06:20 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/19 17:45:49 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipe	*init_pipe(int ac, char **av, char **env)
{
	t_pipe	*new_pipe;

	new_pipe = malloc(sizeof(t_pipe));
	if (new_pipe == NULL)
		return (NULL);
	return (new_pipe);
}
