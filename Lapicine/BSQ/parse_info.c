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
		{
			m_line++;
			continue ;
		}
		if (m_line > 0)
		{
			m_col = 1;
			while (map_str[i++] != '\n')
				m_col++;
			if (m_col != info.col)
				return (0);
		}
		else
			i++;
	}

	if (info.line != m_line)
		return (0);
	return (ft_split(map_str));
}
