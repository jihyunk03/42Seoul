/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:58 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/01 17:02:58 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_message(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	error_exit(t_philo *philo, t_data *data, int errno)
{
	if (errno == ARG_ERR || errno == MUTEX_ERR)
		free_data(data);		// mutex_free도 안에서 해줄것(NULL 제외) >> memset사용했기 때문에 조건만 주면 이들이 알아서 처리 가능
	else if (errno == PHILO_ERR)
		free_philo(philo);		// 이 안에서 data 한번만 free 해줄 것
}
