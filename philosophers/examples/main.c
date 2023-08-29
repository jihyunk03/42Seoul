#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	leaks(void);
void	make_string(char **str);

int	main(void)
{
	char	*str;

	atexit(leaks);
	make_string(&str);
	// free (str);
	return (EXIT_SUCCESS);
}

void	make_string(char **str)
{
	*str = malloc(sizeof(char) * 6);
}

void	leaks(void)
{
	system("leaks --quiet a.out");
}
