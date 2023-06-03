/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_for_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:34:09 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/03 18:17:11 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/*
 * [ dup2의 인자 ]
  * ret = dup2(old_fd <- newfd);
 */

int	main(void)
{
	// file을 open한 setfd(file descriptor)와 이에 대한 redirection을 진행할 ret(file descriptor)
	int		setfd, ret;
	char	message1[] = {"STDERROR from setfd\n"};
	char	message2[] = {"STDERROR from ret\n"};

// picture 1
	// test2에 대해 없다면 생성
	// option: O_APPEND를 사용하여 기존 파일이 있다면 내용 추가(덮어쓰기 X)
	setfd = open("test2", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (setfd < 0)
	{
		printf("FAIL to open\n");
		return (EXIT_FAILURE);
	}

	// 파일 입출력에 대한 fd 변경 전
	printf("printf: setfd 변경 전 > 화면 출력됨\n");

// picture 2
	// setfd에 대한 fd를 define되어 있는 STDOUT_FILENO의 fd가 되도록 복제
	ret = dup2(setfd, STDOUT_FILENO);

	// printf 함수도 STDOUT이므로 setfd로 출력됨
	printf("== ret: dup2(setfd, STDOUT_FILENO) ==\n");
	printf("[setfd]: %d\n[ret]: %d\n[STDOUT_FILENO]: %d\n", setfd, ret, STDOUT_FILENO);
	printf("=====================================\n\n");

// picture 3
	// STDERR_FILENO에 대한 fd를setfd에 대한 fd가 되도록 복제
	ret = dup2(STDERR_FILENO, setfd);

	// ret에 대한 출력은 error로 출력!
	write(setfd, message1, strlen(message1));
	write(ret, message2, strlen(message2));

	// 이미 STDOUT_FILENO에 대한 값을 변경해놓았기 때문에 다음 결과도 파일에 저장
	printf("== ret: dup2(STDERR_FILENO, setfd) ==\n");
	printf("[setfd]: %d\n[ret]: %d\n[STDERR_FILENO]: %d\n", setfd, ret, STDERR_FILENO);
	printf("=====================================\n\n");

	close(setfd);
	close(ret);		// 이미 해당 값이 setfd와 같음
	return (EXIT_SUCCESS);
}
