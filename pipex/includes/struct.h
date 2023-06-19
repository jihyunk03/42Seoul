/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:00:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/19 17:45:46 by jihykim2         ###   ########.fr       */
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
typedef struct s_pipe
{
	int		idx;		// current cmd
	int		cmd;		// count of cmds
	int		here_doc;	// flag for here_doc
	int		prev;		// previous fd for pipe(in)
	int		curr;		// ???????????????   current fd for pipe(out)?
	int		pipe[2];	// pipe
	char	**args;		// array of commands
	char	**envp;		// point of array(res of split PATH)
}	t_pipe;

#endif
