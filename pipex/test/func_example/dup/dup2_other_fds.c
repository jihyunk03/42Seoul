/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_other_fds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:03 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/02 21:26:28 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
// #include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		fd1, fd2;
	char	message[100] = "message from functions\n";
	char	*buf = calloc(sizeof(char), 100);

	// test1에 대해 존재하지 않는다면 만들고 있다면 해당 파일에 대한 권한 검사
	// 여기서의 권한은 읽고 쓰기가 가능한지 확인, O_APPEND 조건을 넣지 않았기에 무조건 덮어씌워짐
	fd1 = open("test1", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd1 < 0)
	{
		printf("FAIL to open\n");
		return (EXIT_FAILURE);
	}

	// fd1에 대하여 fd2에 복사를 하되 해당 fd2의 값은 42로 지정
	fd2 = dup2(fd1, 42);
	printf("num of fd1: %d\nnum of fd2: %d\n", fd1, fd2);

	// fd2가 가리키는 파일에 대해 해당 message를 write(내용이 있던 없던 무조건 덮어씀)
	write(fd2, message, strlen(message));

	// 해당 파일 내용이 잘 덮어 쓰여졌는지 read로 확인
	// BUT, 여기서 내 예상은 message 내용이 출력될 것이라 생각했는데 write 된 이후부터 read가 진행됨
	if (read(fd2, buf, strlen(message)) >= 0)
		printf("===In buf===\n[START]%s[END]\n", buf);
	else
		printf("FAIL to read\n");

	close(fd1);
	close(fd2);

	exit (EXIT_SUCCESS);
}
