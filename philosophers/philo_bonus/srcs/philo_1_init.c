/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:51:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/18 19:33:14 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static int		_check_is_digit(int ac, char **arg);
static t_data	*_init_semaphore(t_data *data);

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		exit (EXIT_FAILURE);
	memset(data, 0, sizeof(t_data));
	if (_check_is_digit(ac, av) == FALSE)
		error_exit(NULL, data, ARG_ERR);
	data->philosophers = ft_atoi(av[1]);
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	data->must_eat = -1;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	if (data->philosophers < 1 || data->die_t < 1 || data->eat_t < 1 \
	|| data->sleep_t < 1 || (ac == 6 && data->must_eat < 1))
		return (ARG_ERR);
	return (_init_semaphore(data));
}

static int	_check_is_digit(int ac, char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (arg[i][j])
			if (ft_isdigit(arg[i][j++]) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}

static t_data	*_init_semaphore(t_data *data)
{
	sem_unlink("./forks");
	sem_unlink("./dead");
	sem_unlink("./print");
	data->forks = sem_open("./forks", O_CREAT, 0644, data->philosophers);
	data->fork_count = data->philosophers;
	data->dead = sem_open("./dead", O_CREAT, 0644, 1);
	data->someone_dead = FALSE;
	data->print = sem_open("./print", O_CREAT, 0644, 1);
	data->no_print = FALSE;
	if (data->forks == SEM_FAILED \
	|| data->dead == SEM_FAILED \
	|| data->print == SEM_FAILED)
		error_exit(NULL, data, SEM_ERR);
	return (data);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->philosophers);
	if (philo == NULL)
		error_exit(NULL, data, PHILO_ERR);
	i = 0;
	while (i < data->philosophers)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].eat_cnt = 0;
		i++;
	}
	return (philo);
}
