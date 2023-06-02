/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:34:09 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/02 21:30:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	// file을 open한 fd(file descriptor)와 이에 대한 redirection을 진행할 ret(file descriptor)
	int	fd, ret;

	// test2에 대해 없다면 생성
	// option: O_APPEND를 사용하여 기존 파일이 있다면 내용 추가(덮어쓰기 X)
	fd = open("test2", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		printf("FAIL to open\n");
		return (EXIT_FAILURE);
	}

	// 파일 입출력에 대한 fd 변경 전
	printf("printf: fd 변경 전 > 화면 출력됨\n");

	// fd

	exit (EXIT_SUCCESS);
}
