/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:55:53 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/21 20:03:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* Example for using usleep */

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		printf("====This is child process====\nnosleep...\n");
		//usleep(100000);
		printf("====child process END!!====\n");
	}
	else
	{
		printf("----This is parent process----\nnosleep!!\n");
		printf("----parent process END!!----\n");
	}
	return (0);
}
