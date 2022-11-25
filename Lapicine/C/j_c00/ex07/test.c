#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		in;
	char	out;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb*=(-1);
		write(1, "-", 1);
	}
	in = nb / 10;
	out = nb % 10 + '0';
	if (in != 0)
	{
		ft_putnbr(in);
		write(1, &out, 1);
	}
	else
	{
		in+='0';
		write(1, &out, 1);
	}
}

int	main(void)
{
	ft_putnbr(-10);
	write(1, "\n", 1);
	ft_putnbr(130);
	write(1, "\n", 1);
	ft_putnbr(-393939024);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(0);
	return (0);
}
