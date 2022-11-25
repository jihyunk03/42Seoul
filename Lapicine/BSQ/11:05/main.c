#include "bsq.h"

void	bsq(char *map_str, int flag)
{
	t_map	info;
	t_max	data;
	char	**map_arr;
	int		**map_int;

	if (map_info(map_str, &info) == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	if (flag)
		map_arr = parse_info(map_str, info);
	else
		map_arr = parse_info2(map_str, info);
	if (map_arr == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	map_int = map_init(info, map_arr);
	if (map_int == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	find_square(map_int, info, &data);
	print_result(map_int, info, data);
}

char	*get_input()
{
	int		i;
	char	c;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * 10000000);
	if (arr == 0)
		return (0);
	i = 0;
	while (read(0, &c, 1) > 0)
	{
	    arr[i] = c;
	    i++;
	}
	arr[i] = 0;
	return (arr);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*map_str;

	if (argc == 1)
	{
		map_str = get_input();
		bsq(map_str, 0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map_str = read_file(argv[i]);
			if (map_str == 0)
				write(2, "map error\n", 10);
			else
				bsq(map_str, 1);
			i++;
		}
	}
}
