/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_allow_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:55:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/16 20:02:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int	main(void)
{
	char	write_msg[BUFFER_SIZE] = "Greetings";
	char	read_msg[BUFFER_SIZE];
	int		fd[2];
	pid_t	pid;

	//파이프 생성
	// if (pipe(fd) == -1)
}
