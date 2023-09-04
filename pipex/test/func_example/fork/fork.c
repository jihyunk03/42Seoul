/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:09:26 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/21 17:44:51 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_all(char *title, int global, int local, int heap);

// 전역 변수, 지역 번수와 동적영역 변수에 따라 값이 달라지는지 확인해보기
int	global_val = 1;							// 전역 변수

int	main(void)
{	// 변수 선언
	int		local_val = 1;					// 지역 변수
	int		*heap_val = malloc(sizeof(int));// 동적영역 변수
	*heap_val = 1;

	// 변수 값 확인
	print_all("value of vars", global_val, local_val, *heap_val);

	// 자식 프로세스 생성
	pid_t	pid;
	pid = fork();
	if (pid == -1)	// fork 실패
	{
		free (heap_val);
		return (1);
	}
	else if (pid == 0)	// 자식 프로세스
	{
		global_val *= 100;
		local_val *= 100;
		*heap_val *= 100;
		print_all("child process", global_val, local_val, *heap_val);
	}
	else	// 부모 프로세스
	{
		global_val *=200;
		local_val *= 200;
		*heap_val *= 200;
		print_all("parent process", global_val, local_val, *heap_val);
	}
	free (heap_val);
	return (0);
}

void	print_all(char *title, int global, int local, int heap)
{
	printf("-----%s-----\n", title);
	printf("global_val: %d\n", global);
	printf("local_val: %d\n", local);
	printf("heap_val: %d\n\n", heap);
}
