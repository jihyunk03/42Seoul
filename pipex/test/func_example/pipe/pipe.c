/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:44:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/09 18:55:58 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#define P_READ		0
#define P_WRITE		1
#define BUFFER_SIZE	4096

void	child_proc(int pipe[2]);
void	child_command(void);
void	parent_proc(int pipe[2], pid_t pid);
void	parent_command(void);

int	main(void)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	printf("[Parent]: fd for Read is %d, fd for write is %d\n", fd[P_READ], fd[P_WRITE]);
	pid = fork();
	if (pid == -1)
	{
		close(fd[P_READ]);
		close(fd[P_WRITE]);
		return (EXIT_FAILURE);
	}
	else if (pid == 0)	/* child process */
		child_proc(fd);
	else				/* parent process */
		parent_proc(fd, pid);
	return (EXIT_SUCCESS);
}

void	child_proc(int pipe[2])
{
	int	fd;
	int	read_fd;
	int	write_fd;

	printf("[Child]: I'm going to close fd for READ\n");
	close(pipe[P_READ]);

	printf("[Child]: I'm going to connect STDOUT to fd for WRITE\n");
	write_fd = dup2(pipe[P_WRITE], STDOUT_FILENO);
	close(pipe[P_WRITE]);
	if (write_fd == -1)
		exit(EXIT_FAILURE);
	printf("\t\t{pipe[P_WRITE]: %d, write_fd: %d, STDOUT: %d}\n", pipe[P_WRITE], write_fd, STDOUT_FILENO);

	printf("[Child]: I'm going to connect STDIN to fd from a file\n");
	fd = open("read.txt", O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	read_fd = dup2(fd, STDIN_FILENO);
	close(fd);
	if (read_fd == -1)
		exit(EXIT_FAILURE);
	printf("\t\t{fd: %d, read_fd: %d, STDIN: %d}\n", fd, read_fd, STDIN_FILENO);

	printf("[Child]: Eventually I'll read from STDIN(file) and write to STDOUT(pipe)\n");
	child_command();
}

void	child_command(void)
{
	int		ret;
	char	buffer[BUFFER_SIZE];

	printf("[Child]: This is child_command\n");
	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
	printf("[Child]: END\n");
}

void	parent_proc(int pipe[2], pid_t pid)
{
	int	fd;
	int	read_fd;
	int	write_fd;

	printf("[Parent]: I'm going to close fd for WRITE\n");
	close(pipe[P_WRITE]);

	printf("[Parent]: I'm going to connect STDIN to fd for READ\n");
	read_fd = dup2(pipe[P_READ], STDIN_FILENO);
	close(pipe[P_READ]);
	if (read_fd == -1)
		exit(EXIT_FAILURE);

	printf("[Parent]: I'm going to connect STDOUT to fd from a file\n");
	fd = open("write.txt", O_WRONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	printf("\t\t{open->fd: %d}\n", fd);
	write_fd = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (write_fd == -1)
		exit(EXIT_FAILURE);

	if (waitpid(pid, NULL, 0) == -1)
		exit(EXIT_FAILURE);

	printf("[Parent]: Eventually I'll read STDIN(pipe) and write to STDOUT(file)\n");
	parent_command();
}

void	parent_command(void)
{
	int		ret;
	char	buffer[BUFFER_SIZE];

	printf("[Parent]: This is parent_command\n");
	ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	write(STDOUT_FILENO, buffer, strlen(buffer));
	printf("[Parent]: END\n");
}
