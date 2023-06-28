/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:12 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 22:37:14 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* includes for my_libft */
# include "../my_libft/libft.h"
# include "../my_libft/ft_printf.h"
# include "../my_libft/get_next_line.h"

/* includes of structs and defines */
# include "./struct.h"

/* includes of functions */
# include <unistd.h>	// open, read, write, close, access, unlink, fork, dup, dup2, pipe, execve
# include <sys/wait.h>	// wait, waitpid
# include <stdlib.h>	// malloc, free, exit
# include <fcntl.h>		// macro for functions(open, unlink)
# include <stdio.h>		// perror
# include <string.h>	// strerror
# include <errno.h>

/* functions */
/* init_pipe */
t_pipe	*init_pipe(int ac, char **av, char **env);

/* multi_process */
void	parent_process(t_pipe *p, int pid);
void	child_process(t_pipe *p, int idx, int ac);


/* split command */
void	split_command(t_pipe *p, char *cmd);
int		cmd_args_len(char *cmd);
int		is_quote(char q, char *tmp_quote);

/* execute command */
void	exec_command(t_pipe *p);


/* error */
int		error_exit(char *s, int true);
int		error_no_command(t_pipe *p);

/* free functions */
void	free_arr_args(char **cmd_args);

#endif
