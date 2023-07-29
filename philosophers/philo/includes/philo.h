/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:15:51 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/28 19:49:56 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./struct.h"
# include "./define.h"
# include "./header.h"

/* functions */
/* libft_utils.c */
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);

/* init_struct.c */
t_data	*init_data(int ac, char **av);

/* error_exit.c */
int		error_message(char *message);

#endif
