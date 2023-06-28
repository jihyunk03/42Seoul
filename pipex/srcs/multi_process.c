/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:35:15 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 22:11:24 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	_begin_child_process(t_pipe *p);
static void	_mid_child_process(t_pipe *p);
static void	_end_child_process(t_pipe *p);

void	parent_process(t_pipe *p, int pid)
{
	close(p->pipe[P_WRITE]);
	if (dup2(p->pipe[P_READ], STDIN_FILENO) == -1)
		perror("dup2(stdin)");
	close(p->pipe[P_READ]);
}

void	child_process(t_pipe *p, int idx, int ac)
{
	if (idx == 2 || (p->here_doc && idx == 3))
		_begin_child_process(p);
	else if (idx < ac - 2)
		_mid_child_process(p);
	else
		_end_child_process(p);	// no pipe
	exec_command(p);	// 인자로 가져간 것들은 모두 free 해줘야 함
}

static void	_begin_child_process(t_pipe *p)
{
	close(p->pipe[P_READ]);
	if (dup2(p->in_fd, STDIN_FILENO) == -1)
		perror("dup2(infile)");
	close(p->in_fd);
	if (dup2(p->pipe[P_WRITE], STDOUT_FILENO) == -1)
		perror("dup2(pipe_write)");
	close(p->pipe[P_WRITE]);
}

static void	_mid_child_process(t_pipe *p)
{
	close(p->pipe[P_READ]);
	if (dup2(p->pipe[P_WRITE], STDOUT_FILENO) == -1)
		perror("dup2(pipe_write)");
	close(p->pipe[P_WRITE]);
}

static void	_end_child_process(t_pipe *p)
{
	if (dup2(p->out_fd, STDOUT_FILENO) == -1)
		perror("dup2(stdout)");
}
