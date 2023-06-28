/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 23:34:41 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	_multi_process_with_pipe(t_pipe *p, int ac, char **av);

int	main(int ac, char **av, char **env)
{
	t_pipe	*pipex;
	int		status;

	if (ac < 5)
		error_exit("usage: the number of arguments is too small\n", FALSE);
	pipex = init_pipe(ac, av, env);
	status = _multi_process_with_pipe(pipex, ac, av);
	// check: close fds, unlink here_doc,
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
		split_command(p, av[i]);
		if (i < ac - 2 && pipe(p->pipe) == -1)
			error_exit("pipe", TRUE);
		pid = fork();
		if (pid == 0)
			child_process(p, i, ac);
		else
			parent_process(p, pid);
		i++;
	}
	while (cmd_cnt--)
		wait(&status);
	return (status);
}
