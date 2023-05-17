/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:32:57 by jihykim2          #+#    #+#             */
/*   Updated: 2023/05/17 17:06:53 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	mode;

	if (ac < 2)
		return (0);
	i = 0;
	while (++i < ac)
	{
		mode = F_OK;
		if (access(av[i], mode) != 0)
			printf("Exist: %s: No such file or directory\n", av[i]);
		else
			printf("Exist: %s: OK\n", av[i]);
		mode = X_OK;
		if (access(av[i], mode) != 0)
			printf("Access: %s: Permission denied\n", av[i]);
		else
			printf("Access: %s: OK\n\n", av[i]);
	}
	return (0);
}
