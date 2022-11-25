/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunlee <jiyunlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:04:11 by jiyunlee          #+#    #+#             */
/*   Updated: 2022/09/15 00:14:21 by jiyunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		line;
	int		col;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_max
{
	int	size;
	int	x;
	int	y;
}	t_max;

int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, int n);
char	**ft_split(char *str);
int		free_str(char *str);
void	free_char(char **str, int size);
void	free_int(int **arr, int size);
int		print_err(void);
char	*read_file(char *fname);
char	**parse_info(char *map_str, t_map info);
char	**parse_info2(char *map_str, t_map info);
int		map_info(char *map_str, t_map *info);
int		**map_init(t_map map_info, char **map_str);
void	find_square(int **sq, t_map info, t_max *data);
void	print_result(int **sq, t_map info, t_max data);

#endif
