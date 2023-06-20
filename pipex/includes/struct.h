/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:00:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/21 07:12:38 by jihykim2         ###   ########.fr       */
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
	int		in_fd;			// infile fd
	int		out_fd;			// outfile fd
	// int		prev_fd;		// previous fd for pipe(in): 이전 파이프에서 읽은 값에 대한 출력 fd값 임시 저장
	// int		curr_fd;		// ???????????????   current fd for pipe(out)?
	// char	**args;		// array of commands
	char	**envp;		// point of array(res of split PATH)
}	t_pipex;

#endif
