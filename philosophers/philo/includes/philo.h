/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:15:51 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/31 16:28:27 by jihykim2         ###   ########.fr       */
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
int		init_data(t_data *new, int ac, char **av);

/* error_exit.c */
int		error_message(char *message);
int		error_data(t_data *data, int errno);

/* free_all.c */
void	free_data(t_data *data);

#endif
