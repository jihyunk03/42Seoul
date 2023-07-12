/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:01:18 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/12 20:21:15 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	_get_map_from_file(int fd, t_maps *new);
static void	_check_valid_map(t_maps *new);

void	check_map(char *file)
{
	t_maps	*new_maps;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_open(file);
	new_maps = malloc(sizeof(new_maps));
	_get_map_from_file(fd, new_maps);
	_check_valid_map(new_maps);
}

static void	_get_map_from_file(int fd, t_maps *new)
{	// 여기서 map의 height를 구할 수 있음.. 줄수 문제지^^
	char	*string;
	char	*line;
	char	*tmp;

	string = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (string == NULL)
			string = line;
		else
		{
			tmp = string;
			string = ft_strjoin(string, line);
			free (tmp);
			free (line);
			// if (string == NULL)
			// 	exit (EXIT_FAILURE);
		}
	}
	if (*string == 0 || string == NULL)
		error_map("map is empty!\n");
	new->map = ft_split(string, '\n');
	free (string);
}

static void	_check_valid_map(t_maps *new)
{

}
