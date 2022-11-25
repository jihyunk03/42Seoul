/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:29:09 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/13 23:40:41 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SQUARE_H
#define FIND_SQUARE_H

// name: info
typedef struct	s_map
{
	int		line;
	int		col;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

// name: data (start index)
typedef struct	s_max
{
	int	size;
	int	x;
	int y;
}	t_max;

#endif
