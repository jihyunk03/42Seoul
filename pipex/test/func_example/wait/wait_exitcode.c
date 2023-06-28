/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_exitcode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:32:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/24 18:36:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
// #include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid;
	pid_t	ret;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		printf("- Child Process: I'll yield Exit Code in 2 -\n");
		printf("- Child Process END -\n");
		return (2);
	}
	else
	{
		printf("= Parent Process: I have a Child Process(id: %d) =\n", pid);
		ret = wait(&status);
		printf("  Parent Process: SUCCESSFULLY got status(%d) from Child Process\n", ret);
		if (WIFEXITED(status))
			printf("  Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
		printf("= Parent Process END =\n");
	}
	return (0);
}
