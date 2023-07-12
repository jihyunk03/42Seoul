/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:30:36 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/12 16:37:07 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
void	print_values(t_data *image);

int	main(void)
{
	t_vars	vars;
	t_data	image;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 500, 500, "TITLE^*^");
	image.img = mlx_new_image(vars.mlx_ptr, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	print_values(&image);
	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			my_mlx_pixel_put(&image, i, j, 0x0000FF00);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, image.img, 0, 0);
	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit (0);
	}
	return (0);
}

void	print_values(t_data *image)
{
	printf("==struct of image==\n");
	printf("[ptr of image]: %p\n", image->img);
	printf("[char of addr]: %s\n", image->addr);
	printf("[bits_per_pixel]: %d\n", image->bits_per_pixel);
	printf("[line_length]: %d\n", image->line_length);
	printf("[endian]: %d\n", image->endian);
}
