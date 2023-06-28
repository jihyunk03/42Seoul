/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_signal_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:32:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/26 20:33:54 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	ret;
	int		status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I will get some of a Signal\n");
		while (1)
			;
	}
	else
	{
		printf("Parent: I have a Child with pid %d\n", pid);
		ret = wait(&status);
		printf("Parent: Successfully got status from %d Child\n", ret);
		if (WIFSIGNALED(status))
			printf("Parent: Exit Code is %d, Signal is %d", WEXITSTATUS(status), WTERMSIG(status));
	}
	return (0);
}
