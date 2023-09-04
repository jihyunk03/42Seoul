/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:00:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/17 17:55:07 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (access(av[i], F_OK | R_OK | W_OK) == 0)
		{
			if (unlink(av[i]) == 0)
				printf("%s\t: unlink >> SUCCESS\n", av[i]);
			else
				printf("%s\t: unlink >> FAIL\n", av[i]);
		}
		else if (access(av[i], F_OK) != 0)
			printf("%s\t: No such file or directory\n", av[i]);
		else
			printf("%s\t: Permission denied\n", av[i]);
	}
	return (0);
}
