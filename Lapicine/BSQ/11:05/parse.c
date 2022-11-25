#include "bsq.h"

int	count_line(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			count++;
			while (str[i] && str[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		j;
	int		arr_index;

	arr = (char **)malloc(sizeof(char *) * (count_line(str) + 1));
	arr_index = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			j = i;
			while (str[j] && str[j] != '\n')
				j++;
			arr[arr_index] = (char *)malloc(sizeof(char) * (j - i) + 1);
			ft_strncpy(arr[arr_index++], &str[i], j - i);
			i = j;
		}
		else
			i++;
	}
	arr[arr_index] = 0;
	return (arr);
}

int	buff_count(char *fname)
{
	int		fd;
	int		count;
	char	c;

	count = 0;
	fd = open(fname, O_RDONLY);
	while (read(fd, &c, 1))
		count++;
	close(fd);
	return (count);
}

char	**parse_info(char *map_str, t_map info)
{
	int	i;
	int	m_line;
	int	m_col;

	i = 0;
	m_line = 0;
	while (map_str[i])
	{
		if (map_str[i++] == '\n')
			m_line++;
		else if (m_line == 0)
			i++;
		else
		{
			m_col = 1;
			i--;
			while (map_str[++i] != '\n')
				m_col++;
			if (m_col != info.col)
				return (0);
		}
	}
	if (info.line != m_line)
		return (0);
	return (ft_split(map_str));
}

char	**parse_info2(char *map_str, t_map info)
{
	int	i;
	int	m_line;
	int	m_col;

	i = 0;
	m_line = 0;
	while (map_str[i])
	{
		if (map_str[i++] == '\n')
			m_line++;
		else if (m_line == 0)
			i++;
		else
		{
			m_col = 1;
			i--;
			while (map_str[++i] != '\n')
				m_col++;
			if (m_col != info.col)
				return (0);
		}
	}
	if (info.line != m_line - 1)
		return (0);
	return (ft_split(map_str));
}

char	*read_file(char *fname)
{
	int		fd;
	int		len;
	char	*buff;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		len = buff_count(fname);
		buff = (char *)malloc(sizeof(char) * len + 1);
		if (buff == 0)
			return (0);
		read(fd, buff, len);
		buff[len] = 0;
	}
	close(fd);
	return (buff);
}
