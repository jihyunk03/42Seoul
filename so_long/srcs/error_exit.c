/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:58:17 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/15 22:26:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_system_call(char *error)
{
	perror(error);
	exit (EXIT_FAILURE);
}

void	error_file(char *filename, char *message)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	if (message == NULL)
		perror(filename);
	else
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
	}
	exit (EXIT_FAILURE);
}

void	error_map(t_maps *maps, char *message)
{// map도 free 안해줘?? -> 조건 따라서 해야할듯~
	if (maps != NULL)
		free_maps(maps);
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
