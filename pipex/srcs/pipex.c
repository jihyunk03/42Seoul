/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 18:22:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	process_cmds(t_pipex *p, int ac, char **av);

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		status;		// for waitpid

	if (ac < 5)
	{
		ft_putstr_fd("argc error: more arguments are needed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pipex = init_pipex(ac, av, env);
	if (pipex == NULL)
		return (EXIT_FAILURE);
	process_cmds(pipex, ac, av);
	return (0);
}

void	process_cmds(t_pipex *p, int ac, char **av)
{
	int	i;
	int	pid;
	int	fd[2];

	i = 2;	// cmd: av[2]부터 시작
	if (p->here_doc == TRUE)
		i++;
	while (i < ac - 1)
	{
		if (pipe(fd) == -1)
			exit(EXIT_FAILURE);		// 다른 방법으로 해야하나..?(마지막에는 NO pipe)
		pid = fork();
		if (pid == 0)
			child_process(p, fd, i, ac, av[i]);
		else
			parent_process(p, fd, pid);
		i++;
	}
}
