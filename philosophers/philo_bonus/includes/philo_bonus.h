/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:11:26 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 19:33:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "./struct_bonus.h"
# include "./define_bonus.h"
# include "./header_bonus.h"

/* philo_1_init */
t_data		*init_data(int ac, char **av);
t_philo		*init_philo(t_data *data);

/* philo_2_start */

/* philo_3_routine */

/* philo_4_monitoring */

/* message_print */
void		print_message(t_philo *philo, char *message);
void		print_dead(t_philo *philo, t_data *data);

/* get_time_utils */
long long	current_time(void);
int			sleep_even_philo(t_data *data);

/* libft_utils */
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);

/* free_all */
void		free_philo(t_philo *philo, int philosophers);
void		free_data(t_data *data);

/* error_exit */
int			error_exit(t_philo *philo, t_data *data, int errno);

#endif
