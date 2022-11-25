#include <unistd.h>

void	ft_print_comb(void)
{
	char c[3];

	c[0] = '0';
	while (c[0] <= '7')
	{
		c[1] = c[0] + 1;
		while (c[1] <= '8')
		{
			c[2] = c[1] + 1;
			while (c[2] <= '9')
			{
				if (c[0] == '7')
				{
					write(1, c, 3);
					break ;
				}
				if (c[0] < c[1] && c[1] < c[2])
				{
					write(1, c, 3);
					write(1, ", ", 2);
				}
				c[2]++;
			}
			c[1]++;
		}
		c[0]++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
