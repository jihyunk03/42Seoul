/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:34:09 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/02 12:38:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("test.txt", O_RDONLY);
	if (fd1 == -1)
		return (1);
	printf("number of fd1: %d\n", fd1);
	fd2 = dup2(fd1, 42);
	printf("\n===After dup2(: Duplication Function) using==\n");
	printf("number of fd1: %d\n", fd1);
	printf("number of fd2: %d\n", fd2);
	close(fd1);
	close(fd2);

	return (0);
}
