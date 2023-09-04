#ifndef PIPEX_TEST_H
# define PIPEX_TEST_H

# define TRUE		1
# define FALSE		0

# include <unistd.h>	// open, read, write, close, access, unlink, fork, dup, dup2, pipe, execve
# include <sys/wait.h>	// wait, waitpid
# include <stdlib.h>	// malloc, free, exit
# include <fcntl.h>		// macro for functions(open, unlink)
# include <stdio.h>		// perror
# include <string.h>	// strerror
# include <errno.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
