/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:12 by jihykim2          #+#    #+#             */
/*   Updated: 2023/09/02 20:48:54 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libftprintf/libft/libft.h"
# include "../libftprintf/ft_printf/ft_printf.h"

# include "./struct.h"

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

t_pipe	*init_pipe(int ac, char **av, char **env);

void	split_command(t_pipe *p, char *cmd);
int		cmd_args_len(char *cmd);
int		is_quote(char q, char *tmp_quote);

void	parent_process(t_pipe *p);
void	child_process(t_pipe *p, int idx, int ac, char **av);
void	exec_command(t_pipe *p);

void	free_pipe(t_pipe *p);
void	free_arr_args(char **arr);
void	free_prev_cmd_args(char **cmd_args);

void	error_exit(t_pipe *p, char *s);
int		error_here_doc(char *for_free);
void	error_check_file_fds(int fd, char *filename);
int		error_no_command(t_pipe *p);
int		error_execute(t_pipe *p, char *cmd_path);

#endif
