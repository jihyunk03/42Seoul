/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:07:31 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/09 22:06:38 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	char	**args;

	if (ac == 1)
		return (EXIT_FAILURE);
	args = malloc(ac * sizeof(char *));
	if (args == NULL)
		return (EXIT_FAILURE);

	i = -1;
	args[ac - 1] = NULL;
	while (++i < ac - 1)
		args[i] = av[i + 1];

	if (execve("/usr/bin/gcc", args, NULL) == -1)
		printf("ERROR\n");
	free(args);
	return (EXIT_SUCCESS);
}
