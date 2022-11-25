#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (1)
	{
		write(1, &c, 1);
		if (c == 'a')
			break ;
		c--;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();

	return 0;
}
