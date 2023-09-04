/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 04:53:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/30 17:51:15 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/pipex_bonus.h"

void	error_exit(t_pipe *p, char *s)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	if (p)
	{
		perror(s);
		free_pipe(p);
	}
	else
		ft_putstr_fd(s, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

int	error_here_doc(char *for_free)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror("heredoc");
	if (for_free)
		free (for_free);
	unlink("_here_doc.txt");
	return (EXIT_FAILURE);
}

void	error_check_file_fds(int fd, char *filename)
{
	if (fd != -1)
		return ;
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": permission denied\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

int	error_no_command(t_pipe *p)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(p->cmd_args[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}

int	error_execute(t_pipe *p, char *cmd_path)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(p->cmd_args[0]);
	free (cmd_path);
	return (127);
}
