/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/27 22:19:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	_multi_process_with_pipe(t_pipe *p, int ac, char **av, int *status);

int	main(int ac, char **av, char **env)
{
	t_pipe	*pipex;
	int		status;		// for waitpid

	if (ac < 5)
	{
		ft_putstr_fd("argc error: more arguments are needed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pipex = init_pipe(ac, av, env);
	_multi_process_with_pipe(pipex, ac, av, &status);
	return (WEXITSTATUS(status));
}

static void	_multi_process_with_pipe(t_pipe *p, int ac, char **av, int *status)
{
	pid_t	pid;
	int		i;
	int		cmd_cnt;

	i = 2;	// cmd: av[2]부터 시작
	if (p->here_doc == TRUE)
		i++;
	cmd_cnt = ac - 1 - i;
	while (i < ac - 1)
	{
		if (i < ac - 2 && pipe(p->pipe) == -1)
			exit(EXIT_FAILURE);		// message: pipe error
		pid = fork();
		if (pid == 0)
			child_process(p, i, ac, av[i]);
		else
			parent_process(p, pid);
		i++;
	}
	while (cmd_cnt--)
		wait(status);
}
