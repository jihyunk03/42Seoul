/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:31:39 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 09:58:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"

typedef struct s_maps
{
	char	**map;
	int		width;		// 타입 다시 고려
	int		height;		// size_t -> int ??
	int		p;			// count of people
	int		c;			// count of collector
	int		e;			// count of exit
	int		move;		// count of moving
	int		x;			// P's x (< width)
	int		y;			// P's y (< height)
	int		end[2];		// locate of end(E)
	int		**visited;	// for check valid maps(flags)
	int		e_flag;		// flag for exit by E
}	t_maps;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_Grass;			// Grass
	void	*img_Wall;			// Wall
	void	*img_Nick;			// Nick
	void	*img_Bluederry;		// Blueberry
	void	*img_Judy_OK;		// Judy
	void	*img_Judy_NO;		// Judy: if 'cnt of c' == 'collected c'
}	t_game;

typedef struct s_vars
{
	struct s_game	*game;
	struct s_maps	*maps;
}	t_vars;

#endif
