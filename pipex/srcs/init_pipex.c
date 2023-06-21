/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:06:20 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 19:50:24 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	_is_here_doc(char *infile);
static void	_get_files_fds(t_pipex *p, int ac, char **av);
static void	_get_here_doc_fd(t_pipex *p, char *limiter);
// static void	_get_envp_arr(t_pipex *p, char **env);

t_pipex	*init_pipex(int ac, char **av, char **env)
{
	t_pipex	*new_pipex;

	new_pipex = malloc(sizeof(t_pipex));
	if (new_pipex == NULL)
		exit (EXIT_FAILURE);	// error(?): memory allocate error
	new_pipex->here_doc = is_here_doc(av[1]);
	_get_file_fds(new_pipex, ac, av);
	// _get_envp_arr(new_pipex, env);
	new_pipex->envp = env;
	return (new_pipex);
}

static int	_is_here_doc(char *infile)
{
	if (ft_strlen(infile) == 8 && ft_strncmp(infile, "here_doc", 8) == 0)
		return (TRUE);
	return (FALSE);
}

static void	_get_files_fds(t_pipex *p, int ac, char **av)
{
	if (p->here_doc == TRUE)
	{
		_get_here_doc_fd(p, av[2]);
		p->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		p->in_fd = open(av[1], O_RDONLY);
		p->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	// error check: open files....? -> open에서 오류가 나더라도 명령들은 정상 작동함...
}

static void	_get_here_doc_fd(t_pipex *p, char *limiter)
{
	char	*line;

	p->in_fd = open("_here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// if (p->in_fd == -1)
	// 	return (-1);	// message: open error
	limiter = ft_strjoin(limiter, "\n");
	if (limiter == NULL)
		exit (EXIT_FAILURE);	// message: strjoin error
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			exit(EXIT_FAILURE);		// message: get_next_line error
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break;
		ft_putstr_fd(line, p->in_fd);
		free(line);
	}
	free(line);		// 함수 안에서 open한 fd는 나중에 다른 함수에서 close 해도 되는가?
}

/* // path가 NULL인 경우, 추가적으로 처리해줘야 함
static void	_get_envp_arr(t_pipex *p, char **env)
{
	int	i;

	if (env == NULL)
		exit (EXIT_FAILURE);		// error 아니면 어떻게 처리?
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	p->envp = ft_split(env[i], ':');
	if (p->envp == NULL)
		exit (EXIT_FAILURE);		// message: ft_split error
}
*/
