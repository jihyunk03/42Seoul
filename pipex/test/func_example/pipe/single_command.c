/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:57:54 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/06 20:54:48 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	/* 1. 부모 프로세스에서 2개의 fd를 저장하기 위한 배열 fds 생성 */
	int		fds[2];
	int		status;		// for waitpid()
	pid_t	pid;
	pid_t	wpid;		// for waitpid()

	/* 2. 배열 fds는 연결된 2개의 fd로 채워짐
	 * fds[0]: 자식 프로세스에서 입력(input)을 읽는(read)데 사용
	 * fds[1]: 부모 프로세스로부터 출력(output)을 쓰는(write)데 사용 */
	pipe(fds);

	/* 3. 자식 프로세스 생성: 부모 프로세스의 fd와 memory 복제 */
	pid = fork();

	/* 4. 현재 실행중인 프로세스 아이디(pid)가 자식 프로세스인지(pid == 0) 검사 */
	if (pid == -1)		/* ERROR */
		return (EXIT_FAILURE);
	else if (pid == 0)	/* 자식 프로세스인 경우 */
	{
		/* 5. dup2(): 자신의 stdin을 pipe의 읽기엔드(read end)와 연결 >> fds[0]
		 * 이때, dup2 함수 동작 시 두번째 인자(stdin)의 fd를 close함 >> STDIN_FILENO colsed!
		 * 이후, 이 자식 프로세스의 stdin은 더이상 키보드가 아닌 fds[0]에서 데이터를 입력 받음 */
		dup2(fds[0], STDIN_FILENO);

		/* 6. 이제 자식 프로세스의 stdin은 데이터를 읽어들일 준비가 되었고,
		 * pipe() 호출에 의해 생성된 fd는 더 이상 필요가 없으므로 해당 fd는 close! */
		close(fds[0]);
		close(fds[1]);

		/* 7. 자식 프로세스는 execvp() 함수를 호출하여 sort 명령을 실행하고,
		 * 부모 프로세스의 모든 데이터가 파이프의 읽기엔드(read end)로 쓰여질 때까지 대기 */
		char	*av[] = {(char *)"sort", NULL};
		if (execvp(av[0], av) < 0)
		{
			/* 8. 부모 프로세스로부터 모든 데이터가 파이프의 입력엔드(read end)를 통해
			 * 전달되면 sort 명령을 통해 데이터를 정렬하고
			 * 해당 결과를 stdout을 통해 터미널 디스플레이로 출력 후 execvp() 종료 사
			 * 자식 프로세스는 default fd인 0, 1, 2를 자동으로 close */
			exit(EXIT_SUCCESS);
		}
	}

	/* 부모 프로세스인 경우 */
	/* 5. 부모 프로세스는 ford() 후 파일 디스크립터 fds[0]을 close
	 * because, 부모 프로세스는 데이터를 읽기(read)는 사용하지 않고 데이터를 쓰기(write)만 사용 */
	close(fds[0]);
	// 자식 프로세스에게 전달하고자 하는 단어 배열
	const char	*words[] = {"pear", "peach", "apple", "seoul", "jihyun"};
	size_t		numwords = sizeof(words) / sizeof(words[0]);

	/* 6. dprintf() 함수를 이용하여 자식 프로세스에게 전달하고자 한 단어 배열(words)들을
	 * 파이프의 쓰기엔드(writable end)인 fds[1]에 씀(write)
	 * 이때, 각 단어의 끝에는 '\n'을 붙여 sort 명령이 한 줄당 한 단어씩 받을 수 있도록 함 */
	for (size_t i = 0; i < numwords; i++)
		dprintf(fds[1], "%s\n", words[i]);

	/* 7. 모든 단어들을 전송한 후에 fds[1]을 close
	 * 이때, 자동으로 EOF(end-of-file)이 전송되고, 그 뒤에 자식 프로세스는 sord 명령 수행 */
	close (fds[1]);

	/* 8. waitpid() 함수를 호출하여 자식 프로세스가 종료될 때까지 wait */
	wpid = waitpid(pid, &status,  0);

	/* 9. 자식 프로세스가 종료되고 나면 부모 프로세스도 종료*/
	if (wpid == pid && WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (-1);
}
