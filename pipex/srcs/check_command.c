/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 03:47:22 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 23:24:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**split_command(t_pipex *p, char *cmd)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	if (cmd_arr == NULL)
		exit(EXIT_FAILURE);
	return (cmd_arr);
}
