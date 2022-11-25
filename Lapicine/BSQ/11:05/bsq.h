#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#include <stdio.h>

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

int		map_error(char **map_error);
char	*read_file(char *fname);
char	**parse_info(char *map_str, t_map info);
char	**parse_info2(char *map_str, t_map info);
int		map_info(char *map_str, t_map *info);
int		**map_init(t_map map_info, char **map_str);
void	find_square(int **sq, t_map info, t_max *data);
void	print_result(int **sq, t_map info, t_max data);

#endif
