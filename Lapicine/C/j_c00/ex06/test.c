#include <unistd.h>

void	comb_print(int a, int b, char *c)
{
	c[0] = a / 10 + '0';
	c[1] = a % 10 + '0';
	c[3] = b / 10 + '0';
	c[4] = b % 10 + '0';
	write(1, c, 5);
	write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	char	c[5];

	a = 0;
	c[2] = ' ';
	while (a < 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a < b)
				comb_print(a, b, c);
			b++;
		}
		a++;
	}
	write(1, "98 99", 5);
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
