/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 04:53:02 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/26 12:59:18 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_exit(char *s, int true)
{
	if (true)
	{
		perror(s);
		return (errno);
	}
	ft_putchar_fd(s, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	error_no_command(char *no_path)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(no_path, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}
