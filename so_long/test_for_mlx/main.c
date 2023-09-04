#include "./main.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img1 = mlx_xpm_file_to_image(mlx, "../images/Blueberry.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "../images/Grass.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "../images/Judy_NO.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "../images/Judy_OK.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "../images/Nick.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "../images/Wall.xpm", &img_width, &img_height);
	img7 = mlx_xpm_file_to_image(mlx, "../images/Nick.xpm", &img_width, &img_height);

	printf("void *: %p\n", img1);

	mlx_put_image_to_window(mlx, win, img1, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 0);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	mlx_put_image_to_window(mlx, win, img6, 128, 64);
	mlx_put_image_to_window(mlx, win, img7, 128, 64);

	mlx_loop(mlx);
	return (0);
}









/*
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
*/
