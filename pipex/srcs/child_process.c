/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:35:15 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 21:53:16 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_pipex *p, int idx, int ac, char *cmd)
{
	p->path = split_command(cmd);
	if (idx == 2 || (p->here_doc && idx == 3))
		_begin_process(p);
	else if (idx < ac - 2)
		_mid_process(p);
	else
		_end_process(p);	// no pipe
	exec_command(p, cmd);
}

static void _begin_process(t_pipex *p)
{
	close(p->pipe[P_READ]);
	if (dup2(p->in_fd, STDIN_FILENO) == -1)
		perror("dup2(infile)");
	close(p->in_fd);
	if (dup2(p->pipe[P_WRITE], STDOUT_FILENO) == -1)
		perror("dup2(pipe_write)");
	close(p->pipe[P_WRITE]);
}

static void	_mid_process(t_pipex *p)
{
	close(p->pipe[P_READ]);
	if (dup2(p->pipe[P_WRITE], STDOUT_FILENO) == -1)
		perror("dup2(pipe_write)");
	close(p->pipe[P_WRITE]);
}

static void	_end_process(t_pipex *p)
{
	if (dup2(p->out_fd, STDOUT_FILENO) == -1)
		perror("dup2(stdout)");
}
