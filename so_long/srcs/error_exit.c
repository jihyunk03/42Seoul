/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:58:17 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/12 18:26:16 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_open(char *filename)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	perror(filename);
	exit (EXIT_FAILURE);
}

void	error_map(char *message)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
