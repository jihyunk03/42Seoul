/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:31:39 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 18:27:52 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"

typedef struct s_maps
{
	char	**map;
	int		width;
	int		height;
	int		p;
	int		c;
	int		e;
	int		move;
	int		x;
	int		y;
	int		end[2];
	int		**visited;
	int		e_flag;
}	t_maps;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_grass;
	void	*img_wall;
	void	*img_nick;
	void	*img_bluederry;
	void	*img_judy_ok;
	void	*img_judy_no;
}	t_game;

typedef struct s_vars
{
	struct s_game	*game;
	struct s_maps	*maps;
}	t_vars;

#endif
