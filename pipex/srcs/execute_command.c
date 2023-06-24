/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:07:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/24 15:14:13 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_command(t_pipe *p, char **cmd_arr)
{
	char	*cmd_path;		// path for exec() first argument
	int		i;

	i = 0;
	if (execve(cmd_arr[i], cmd_arr, p->envp) == 0)	// 절대 경로인 경우
		exit (EXIT_SUCCESS);
	while (p->path[i])
	{
		cmd_path = ft_strjoin(p->path[i], cmd_arr[0]);
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
	perror(cmd_arr[0]);		// 아마 perror가 안되면 직접 문자열을 적어야 함
}
