/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/09/02 20:49:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_pipex/pipex.h"

static int	_multi_process_with_pipe(t_pipe *p, int ac, char **av);

int	main(int ac, char **av, char **env)
{
	t_pipe	*pipe;
	int		status;

	if (ac != 5)
		error_exit(NULL, "usage: the number of args must be 5 (madatory)\n");
	pipe = init_pipe(ac, av, env);
	status = _multi_process_with_pipe(pipe, ac, av);
	free_pipe(pipe);
	return (WEXITSTATUS(status));
}

static int	_multi_process_with_pipe(t_pipe *p, int ac, char **av)
{
	pid_t	pid;
	int		i;
	int		cmd_cnt;
	int		status;

	i = 2;
	if (p->here_doc == TRUE)
		i++;
	cmd_cnt = ac - 1 - i;
	while (i < ac - 1)
	{
		free_prev_cmd_args(p->cmd_args);
		split_command(p, av[i]);
		if (pipe(p->pipe) == -1)
			error_exit(p, "pipe");
		pid = fork();
		if (pid == 0)
			child_process(p, i, ac, av);
		else
			parent_process(p);
		i++;
	}
	while (cmd_cnt--)
		wait(&status);
	return (status);
}
