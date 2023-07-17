/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:31:39 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/17 22:38:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./header.h"

# define TRUE 1
# define FALSE 0
# define ERROR "Error\n"

typedef struct s_maps
{
	char	**map;		// width, height가 모두 정해져야 할 수 있음
	size_t	width;
	size_t	height;
	int		p;			// count of people
	int		c;			// count of collector
	int		e;			// count of exit
	int		**visited;	// for check valid maps(flag)
	int		x;	// P's x (< width)
	int		y;	// P's y (< height)
	int		flag;	// flag for exit by E >> 아직 초기화 안함!!!!!!!!
}	t_maps;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


#endif
