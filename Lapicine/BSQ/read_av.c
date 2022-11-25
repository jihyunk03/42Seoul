#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int cnt = 0;
	char *buf = NULL;
	char arr[10];
	int i = 0;

	while (read(0, buf, 1) >= 0)
	{
		arr[i] = *buf;
		//ft_putchar(*buf);
		//printf("%s\n", buf);
		cnt++;
	}
	//while (read(0, buf, 1) > 0)
	//	arr[i] = *buf;

	printf("%s", arr);
	return (0);
}
