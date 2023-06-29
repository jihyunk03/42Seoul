/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:07:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/29 20:32:46 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/pipex_bonus.h"

static char	*_check_command_path(t_pipe *p);

void	exec_command(t_pipe *p)
{
	char	*cmd_path;

	cmd_path = _check_command_path(p);
	if (cmd_path == NULL)
		exit (error_no_command(p));
	if (execve(cmd_path, p->cmd_args, p->envp) == -1)
		exit (error_execute(p, cmd_path));
}

static char	*_check_command_path(t_pipe *p)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	if (access(p->cmd_args[0], X_OK) == 0)
		return (ft_strdup(p->cmd_args[0]));
	i = 0;
	while (p->path[i])
	{
		tmp = ft_strjoin(p->path[i], "/");
		if (tmp == NULL)
			exit (EXIT_FAILURE);
		cmd_path = ft_strjoin(tmp, p->cmd_args[0]);
		free (tmp);
		if (cmd_path == NULL)
			exit (EXIT_FAILURE);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free (cmd_path);
		i++;
	}
	return (NULL);
}
