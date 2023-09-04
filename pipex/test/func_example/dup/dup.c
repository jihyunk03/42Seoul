/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:49:33 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/02 17:00:48 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int 	fd1, fd2;
	char	*buf1, *buf2;

	fd1 = open("test.txt", O_RDONLY);
	if (fd1 == -1)
		return (1);
	fd2 = dup(fd1);
	buf1 = calloc(sizeof(char), 6);
	buf2 = calloc(sizeof(char), 11);
	if (read(fd1, buf1, 5) == -1 || read(fd2, buf2, 10) == -1)
	{
		printf("error in read()\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("read(fd1): %s\n[END]\n", buf1);
		printf("read(fd2): %s\n[END]\n", buf2);
	}
	close(fd1);
	close(fd2);
	exit (EXIT_SUCCESS);
}
