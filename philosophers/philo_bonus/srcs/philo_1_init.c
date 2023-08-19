/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:32 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/19 21:24:25 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	_check_is_digit(int ac, char **arg);
static void	_init_semaphore(t_philo *philo);

t_philo *init_philo(int ac, char **av)
{
	t_philo	*philo;

	_check_is_digit(ac, av);
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit (EXIT_FAILURE);
	memset(philo, 0, sizeof(t_philo));
	philo->philosophers = ft_atoi(av[1]);
	philo->die_t = ft_atoi(av[2]);
	philo->eat_t = ft_atoi(av[3]);
	philo->sleep_t = ft_atoi(av[4]);
	philo->must_eat = -1;
	if (ac == 6)
		philo->must_eat = ft_atoi(av[5]);
	if (philo->philosophers < 1 || philo->die_t < 0 || philo->eat_t < 0 \
	|| philo->sleep_t < 0 || (ac == 6 && philo->must_eat < 1))
		error_exit(philo, ARG_ERR);
	philo->child_id = malloc(sizeof(pid_t) * philo->philosophers);
	if (philo->child_id == NULL)
		error_exit(philo, ALLOC_FAIL);
	_init_semaphore(philo);
	return (philo);
}

static void	_check_is_digit(int ac, char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (arg[i][j])
			if (ft_isdigit(arg[i][j++]) == FALSE)
				error_exit(NULL, ARG_ERR);
	}
	return (TRUE);
}

static void	_init_semaphore(t_philo *philo)
{
	sem_unlink(FORK_SEM);
	sem_unlink(PRINT_SEM);
	philo->forks = sem_open(FORK_SEM, O_CREAT, 0644, philo->philosophers);
	philo->fork_count = philo->philosophers;
	philo->print = sem_open(PRINT_SEM, O_CREAT, 0644, 1);
	philo->no_print = FALSE;
	if (philo->forks == SEM_FAILED \
	|| philo->print == SEM_FAILED)
		error_exit(philo, SEM_ERR);
}
