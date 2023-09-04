/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:50:32 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/24 17:40:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		printf("=====This is Child Process=====\n");
		printf("=====END: Child Process=====\n");
		// return (0);
	}
	else
	{
		printf("-----This is Parent Process-----\n");
		printf("I have child process(id: %d)\n", pid);
		while (1)
			;
		// wait(0);
		printf("-----END: Parent Process-----\n");
	}
	return (0);
}
