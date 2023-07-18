/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:30:36 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/18 22:17:38 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_leaks(void);
void	print_maps(t_maps *maps);

int	main(int ac, char **av)
{
	t_maps	*maps;

	atexit(check_leaks);	// check leaks in so_long
	if (ac != 2)
		error_message("arguments: must be only one file\n");
	maps = init_maps();
	maps->map = get_map(av[1]);
	check_map(maps);

	// print_maps(maps);
	// free_maps(maps);

	play_game(maps);
	return (EXIT_SUCCESS);
}









void	check_leaks(void)
{
	system("leaks --quiet so_long");
}

void	print_maps(t_maps *maps)
{
	int	i;

	i = 0;
	ft_printf("====valid map====\n");
	while (maps->map[i])
		ft_printf("%s\n", maps->map[i++]);
	ft_printf("=================\n");
	ft_printf("width: %d\n", maps->width);
	ft_printf("height: %d\n", maps->height);
	ft_printf("=================\n");
	ft_printf("P: (%d, %d)\n", maps->x, maps->y);
	ft_printf("C: %d\n", maps->c);
	ft_printf("E: %d\n", maps->e);
	ft_printf("=================\n");
}
