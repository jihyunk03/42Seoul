/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:35:15 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 09:36:21 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_pipex *p, int pipe[2], int idx, int ac, char *cmd)
{
	char	**cmd_arr;

	cmd_arr = split_command(cmd);
	if (idx == 2 || (p->here_doc && idx == 3))
		_begin_process(p, pipe, cmd_arr);
	else if (idx < ac - 2)
		_mid_process();
	else
		_end_process();
}

static void _begin_process(t_pipex *p, int pipe[2], char **cmd_arr)
{

}
