/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:35:15 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/23 17:33:58 by jihykim2         ###   ########.fr       */
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

void	child_process(t_pipe *p, int idx, int ac, char *cmd)
{
	char	**cmd_arr;
	char	*cmd_path;

	cmd_arr = split_command(p, cmd);
	// access 권한 검사 이유: 에러가 cmd가 없어서인지 확인용도..? >> 근데 이건 exec에서 다 걸러줌
	// check_command(p, cmd);
	// 만약 여기서 access 처리에서 에러가 난다면 pipe는 어떻게 되는가? 이도 따로 처리해줘야 할듯?
	if (idx == 2 || (p->here_doc && idx == 3))
		_begin_child_process(p);
	else if (idx < ac - 2)
		_mid_child_process(p);
	else
		_end_child_process(p);	// no pipe
	exec_command(p, cmd);	// 인자로 가져간 것들은 모두 free 해줘야 함
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
