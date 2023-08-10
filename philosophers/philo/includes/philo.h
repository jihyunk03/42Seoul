/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:15:51 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/11 02:46:45 by jihykim2         ###   ########.fr       */
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
void	*ft_calloc(size_t count, size_t size);

/* init_struct.c */
int		init_data(t_data *new, int ac, char **av);
t_philo	*init_philo(t_data *data);

/* start_philo.c */
int		start_philo(t_philo *philo, t_data *data);

/* routine_utils.c */
void	*start_routine(void *ph);


/* finish_philo.c */
void	finish_philo(t_philo *philo, t_data *data);

/* philo_utils.c */
long long	current_time(void);
void	print_message(t_philo *philo, char *message);
int		check_dead(t_data *data);

/* error_exit.c */
int		error_message(char *message);
int		error_exit(t_philo *philo, t_data *data, int errno);

/* free_all.c */
void	free_data(t_data *data);
void	free_philo(t_philo *philo, int philosophers);

#endif
