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

#include "../includes_pipex/pipex.h"

static int	_is_here_doc(char *infile);
static void	_get_file_fds(t_pipe *p, int ac, char **av);
static void	_make_here_doc_file(char *limiter);
static void	_get_path_arr(t_pipe *p);

t_pipe	*init_pipe(int ac, char **av, char **env)
{
	t_pipe	*new_pipex;

	new_pipex = malloc(sizeof(t_pipe));
	if (new_pipex == NULL)
		exit (EXIT_FAILURE);
	new_pipex->here_doc = _is_here_doc(av[1]);
	_get_file_fds(new_pipex, ac, av);
	new_pipex->envp = env;
	_get_path_arr(new_pipex);
	new_pipex->cmd_args = NULL;
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
		_make_here_doc_file(av[2]);
		p->in_fd = open("_here_doc.txt", O_RDONLY);
		p->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		p->in_fd = open(av[1], O_RDONLY);
		p->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
}

static void	_make_here_doc_file(char *limiter)
{
	char	*line;
	int		fd;

	fd = open("_here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror("open(here_doc)");
	limiter = ft_strjoin(limiter, "\n");
	if (limiter == NULL)
		exit (error_here_doc(NULL));
	while (TRUE)
	{
		ft_printf("heredoc> ");
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			exit (error_here_doc(limiter));
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
}

static void	_get_path_arr(t_pipe *p)
{
	char	*env_path;
	int		i;

	if (p->envp == NULL)
		exit (EXIT_FAILURE);
	i = 0;
	while (p->envp[i])
	{
		if (ft_strncmp(p->envp[i], "PATH=", 5) == 0)
		{
			env_path = p->envp[i] + 5;
			break ;
		}
		i++;
	}
	if (p->envp[i] == NULL || *env_path == 0)
		exit (EXIT_FAILURE);
	p->path = ft_split(env_path, ':');
	if (p->path == NULL)
		exit (EXIT_FAILURE);
}
