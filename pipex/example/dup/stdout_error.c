/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:37:05 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/03 18:10:55 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	write(STDOUT_FILENO, "11111\n", 6);
	write(STDERR_FILENO, "22222\n", 6);

	// fd = open("test3", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	fd = 0;
	dup2(fd, STDERR_FILENO);

	printf("\nfd, STDERR\n%d, %d\n\n", fd, STDERR_FILENO);
	write(fd, "00000\n", 6);
	write(STDERR_FILENO, "22222\n", 6);

	return (0);
}
