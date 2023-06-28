/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:54:51 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/29 06:28:20 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipe(t_pipe *p)
{
	if (p == NULL)
		return ;
	if (p->here_doc == TRUE)
		unlink("_here_doc.txt");
	close(p->out_fd);
	free_arr_args(p->path);
	free (p);
}

void	free_arr_args(char **cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i])
		free (cmd_args[i++]);
	free (cmd_args);
}

void	free_prev_cmd_args(char **cmd_args)
{
	if (cmd_args == NULL)
		return ;
	free_arr_args(cmd_args);
}
