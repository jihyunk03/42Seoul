/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/31 16:28:32 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_message(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	error_data(t_data *data, int errno)
{

}
