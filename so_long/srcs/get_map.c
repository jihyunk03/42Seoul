/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:51:09 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/15 22:59:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	_get_file_size(char *filename);
static char	**_read_and_parse_map(char *filename, size_t size);

char	**get_map(char *filename)
{
	size_t	size;
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		error_file(filename, ": invalid file name\n");
	if (ft_strncmp(filename + len - 4, ".ber", 5) != 0)
		error_file(filename, ": invalid file extension\n");
	size = _get_file_size(filename);
	return (_read_and_parse_map(filename, size));
}

static int	_get_file_size(char *filename)
{
	size_t	file_size;
	char	buf[DEFAULT_SIZE];
	int		fd;
	int		read_size;

	file_size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_system_call(filename);
	while (TRUE)
	{
		read_size = read(fd, buf, DEFAULT_SIZE);
		if (read_size < 0)
			error_system_call(filename);
		if (read_size == 0)
			break ;
		file_size += read_size;
	}
	close(fd);
	if (file_size == 0)
		error_file(filename, ": empty file!\n");
	return (file_size);
}

static char	**_read_and_parse_map(char *filename, size_t size)
{
	char	**map;
	char	*string;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_system_call(filename);
	string = malloc(sizeof(char) * (size + 1));
	if (string == NULL)
		exit (EXIT_FAILURE);
	if (read(fd, string, size) < 0)
	{
		free(string);
		error_system_call(filename);
	}
	string[size] = '\0';
	close(fd);
	map = ft_split(string, '\n');
	free(string);
	if (map == NULL)
		exit (EXIT_FAILURE);	// fail to split
	return (map);
}
