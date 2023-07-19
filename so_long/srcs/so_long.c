/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:30:36 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/20 06:02:37 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void			check_leaks(void);
static t_maps	*_init_maps(void);

int	main(int ac, char **av)
{
	t_maps	*maps;

	atexit(check_leaks);	// check leaks in so_long
	if (ac != 2)
		error_message("arguments: must be only one file\n");
	maps = _init_maps();
	maps->map = get_map(av[1]);
	check_map(maps);

	play_game(maps);

	// free_maps(maps);
	return (EXIT_SUCCESS);
}

static t_maps	*_init_maps(void)
{
	t_maps	*new_maps;

	new_maps = malloc(sizeof(t_maps));
	if (new_maps == NULL)
		exit (EXIT_FAILURE);
	new_maps->map = NULL;
	new_maps->width = 0;
	new_maps->height = 0;
	new_maps->p = 0;
	new_maps->c = 0;
	new_maps->e = 0;
	new_maps->visited = NULL;
	new_maps->x = 0;	// 굳이..?
	new_maps->y = 0;	// same as x
	new_maps->e_flag = FALSE;
	return (new_maps);
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
