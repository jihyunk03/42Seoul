/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:31:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 04:53:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./struct.h"
# include "./define.h"
# include "./header.h"

/* init_struct.c */
t_maps	*init_maps(void);
void	init_visited(t_maps *maps);
t_game	*init_game(t_maps *maps);

/* get_map.c */
char	**get_map(char *filename);


/* check_map.c */
void	check_map(t_maps *new_maps);
void	check_valid_map(t_maps *maps);

/* play_game.c */
void	play_game(t_maps *maps);


/* error_exit.c */
void	error_message(char *message);
void	error_system_call(char *error);
void	error_file(char *filename, char *message);
void	error_map(t_maps *maps, char *message);

/* free_all.c */
void	free_maps(t_maps *maps);
void	free_visited(t_maps *maps);
void	free_map(t_maps *maps);

#endif
