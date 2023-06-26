/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:07:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/26 12:59:40 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*_check_command_path(t_pipe *p, char *cmd);

void	exec_command(t_pipe *p, char **cmd_arr)
{
	char	*cmd_path;		// path for exec() first argument

	if (execve(cmd_arr[0], cmd_arr, p->envp) == 0)	// 절대 경로인 경우
		exit (EXIT_SUCCESS);
	cmd_path = _check_command_path(p, cmd_arr[0]);
	if (cmd_path == NULL)
		exit (error_no_command(cmd_arr[0]));
	if (execve(cmd_path, cmd_arr, p->envp) == -1)
	{
		free (cmd_path);	// cmd_arr도 free?
		exit (127);		// exit number(127) in terminal
	}
	free (cmd_path);
}

static char	*_check_command_path(t_pipe *p, char *cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	while (p->path[i])
	{
		tmp = ft_strjoin(p->path[i], "/");
		if (tmp == NULL)
			exit (EXIT_FAILURE);		// error (1)
		cmd_path = ft_strjoin(tmp, cmd);
		free (tmp);
		if (cmd_path == NULL)
			exit (EXIT_FAILURE);		// error (1)
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free (cmd_path);
		i++;
	}
	return (NULL);
}

/*
	if (execve(cmd_arr[0], cmd_arr, p->envp) == 0)	// 절대 경로인 경우
		exit (EXIT_SUCCESS);
	i = 0;
	while (p->path[i])
	{
		tmp = ft_strjoin(p->path[i], "/");
		if (tmp == NULL)
			exit (EXIT_FAILURE);		// message: strjoin error
		cmd_path = ft_strjoin(tmp, cmd_arr[0]);
		free (tmp);
		if (cmd_path == NULL)
			exit (EXIT_FAILURE);		// message: strjoin error, [유의]자식 프로세스만 종료됨 >> path_arr 모두 free해야 함
		if (execve(cmd_path, cmd_arr, p->envp) == 0)
		{
			free (cmd_path);		// path_arr도 free해야 함
			exit (EXIT_SUCCESS);
		}
		free (cmd_path);
		i++;
	}
	exit (127);
*/
