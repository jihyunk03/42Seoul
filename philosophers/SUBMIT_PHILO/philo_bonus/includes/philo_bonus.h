/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:40 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/20 22:42:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "./struct_bonus.h"
# include "./define_bonus.h"
# include "./header_bonus.h"

t_philo		*init_philo(int ac, char **av);

void		child_routine(t_philo *philo);
void		wait_and_check_child(t_philo *philo);

void		print_message(t_philo *philo, char *message);
long long	current_time(void);
int			sleep_even_philo(int die_time, int eat_time);

void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

int			error_exit(t_philo *philo, int errno);
void		free_philo(t_philo *philo);

#endif
