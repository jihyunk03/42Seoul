#include <unistd.h>

int	main(void)
{
	//int i = 0;
	char buf[1024];
	//char arr[1024];

	while (read(0, buf, 1) == 1)
	{
		write(1, "|", 1);
		write(1, buf, 1);
		if (buf[0] == '\n')
			break;

		//arr[i++] = *(buf++);
	}

	// ---for printing arr---
	//while (
	return (0);
}
