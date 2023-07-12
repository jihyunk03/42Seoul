/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:31:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/12 18:26:03 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./struct.h"
# include "../mlx/mlx.h"
# include "../my_libft/libft/libft.h"
# include "../my_libft/ft_printf/ft_printf.h"
# include "../my_libft/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* functions */
/* check_map. */
void	check_map(char *file);


/* error_exit.c */
void	error_open(char *filename);
void	error_map(char *message);


#endif
