/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:31:39 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/18 21:57:06 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"

typedef struct s_maps
{
	char	**map;
	size_t	width;		// 타입 다시 고려
	size_t	height;		// size_t -> int ??
	int		p;			// count of people
	int		c;			// count of collector
	int		e;			// count of exit
	int		**visited;	// for check valid maps(flags)
	int		x;			// P's x (< width)
	int		y;			// P's y (< height)
	int		e_flag;		// flag for exit by E
}	t_maps;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_0;		// Grass
	void	*img_1;		// Wall
	void	*img_p;		// Nick
	void	*img_c;		// Blueberry
	void	*img_e;		// Judy
}	t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


#endif
