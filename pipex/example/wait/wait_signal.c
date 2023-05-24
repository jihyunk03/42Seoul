/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:31:21 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/24 19:07:18 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
// #include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void	print_sig(int sig);

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
		printf("- Child Process FORK -\n");
		signal(SIGCONT, print_sig);
		printf("  Child Process: I'll be stopped~\n");
		while (1)
			;
		printf("- Child Process END -\n");
	}
	else
	{
		printf("= Parent Process FORK(Child id: %d) =\n", pid);
		ret = waitpid(pid, &status, WUNTRACED);
		printf("  Parent: Child has been stopped\n");
		printf("  Parent: Successfully got status from %d Child\n", ret);
		if (WIFSTOPPED(status))
			printf("  Parent: Exit Code is %d, Signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
		usleep(10);
		ret = waitpid(pid, &status, WCONTINUED | WNOHANG);
		printf("  Parent: Child has been continued\n");
		printf("  Parent: Successfully got status from %d Child\n", ret);
		if (WIFCONTINUED(status))
			printf("  Parent: Exit Code is %d, Signal is %d\n", WSTOPSIG(status), WTERMSIG(status));
		printf("= Parent Process END =\n");
	}

	return (0);
}

void	print_sig(int sig)
{
	printf("  Child Process: I've got %d Signal\n", sig);
}
