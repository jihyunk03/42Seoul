/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:00:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/29 06:44:11 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define TRUE		1
# define FALSE		0

# define P_READ		0
# define P_WRITE	1

typedef struct s_pipex
{
	int		here_doc;
	int		in_fd;
	int		out_fd;
	int		pipe[2];
	char	**envp;
	char	**path;
	char	**cmd_args;
}	t_pipe;

#endif
