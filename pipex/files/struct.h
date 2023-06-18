/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:00:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/07 21:47:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define P_READ		0;
# define P_WRITE	1;

typedef struct s_pipe
{
	int		idx;
	int		cmd;
	int		prev;
	int		curr;
	int		fd[2];
	char	**arr;
	char	**env;
}	t_pipe;

#endif
