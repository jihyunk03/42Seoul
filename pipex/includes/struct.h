/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:00:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 21:42:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* defines for macro */
# define TRUE		1
# define FALSE		0
# define P_READ		0
# define P_WRITE	1

/* typedef */
typedef struct s_pipex
{
	int		here_doc;	// flag for here_doc
	int		in_fd;		// infile fd
	int		out_fd;		// outfile fd
	int		pipe[2];	// for parent-child process interacting
	char	**envp;		// point of array(res of split PATH) >> 인자 그대로임
	char	**path;		// for exec-function's argument: for checking accessible
}	t_pipex;

#endif
