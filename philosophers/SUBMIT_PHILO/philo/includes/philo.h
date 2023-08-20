/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:15:51 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 22:36:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./struct.h"
# include "./define.h"
# include "./header.h"

int			init_data(t_data *data, int ac, char **av);
t_philo		*init_philo(t_data *data);

int			start_philo(t_philo *philo, t_data *data);
int			ph_eat(t_philo *philo, t_data *data);
int			ph_sleep_and_think(t_philo *philo, t_data *data);

int			check_dead(t_philo *philo, t_data *data);
int			philo_dead(t_philo *philo, t_data *data);
int			someone_dead(t_data *data);
long long	current_time(void);
int			sleep_even_philo(t_data *data);
void		print_message(t_philo *philo, char *message);
void		print_dead(t_philo *philo, t_data *data);

void		free_philo(t_philo *philo, int philosophers);
void		free_data(t_data *data);

int			error_message(char *message);
int			error_exit(t_philo *philo, t_data *data, int errno);

void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);

#endif
