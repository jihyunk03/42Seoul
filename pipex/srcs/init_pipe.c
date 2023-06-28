/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:06:20 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 23:11:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	_is_here_doc(char *infile);
static void	_get_file_fds(t_pipe *p, int ac, char **av);
static void	_get_here_doc_fd(t_pipe *p, char *limiter);
static void	_get_path_arr(t_pipe *p, char **env);

t_pipe	*init_pipe(int ac, char **av, char **env)
{
	t_pipe	*new_pipex;

	new_pipex = malloc(sizeof(t_pipe));
	if (new_pipex == NULL)
		exit (EXIT_FAILURE);
	new_pipex->here_doc = is_here_doc(av[1]);
	_get_file_fds(new_pipex, ac, av);
	_get_path_arr(new_pipex, env);
	new_pipex->envp = env;
	return (new_pipex);
}

static int	_is_here_doc(char *infile)
{
	if (ft_strlen(infile) == 8 && ft_strncmp(infile, "here_doc", 8) == 0)
		return (TRUE);
	return (FALSE);
}

static void	_get_file_fds(t_pipe *p, int ac, char **av)
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

static void	_get_here_doc_fd(t_pipe *p, char *limiter)
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
	free(line);
	// 함수 안에서 open한 fd는 나중에 다른 함수에서 close 해도 되는가?
	// >> ㅇㅇ 가능함, 그리고 여기서 open 한 file은 끝낼 때 unlink 해줘야 함
}

// path가 NULL인 경우, 추가적으로 처리해줘야 함
static void	_get_path_arr(t_pipe *p, char **env)
{
	char	*env_path;
	int		i;

	if (env == NULL)
		exit (EXIT_FAILURE);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			env_path = env[i] + 5;
			break ;
		}
		i++;
	}
	if (env[i] == NULL || *env_path == NULL)
		exit (EXIT_FAILURE);		// message: no PATH or PATH == NULL
	p->envp = ft_split(env_path, ':');
	if (p->envp == NULL)
		exit (EXIT_FAILURE);
}
