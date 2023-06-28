/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:54:51 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 22:21:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_arr_args(char **cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i])
		free (cmd_args[i++]);
	free (cmd_args);
}
