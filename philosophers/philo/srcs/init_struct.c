/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:44:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/09 09:20:18 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	_init_mutex_data(t_data *new);

int	init_data(t_data *new, int ac, char **av)
{	// ft_atoi의 결과가 이상한 경우(숫자가 아닌 것이 들어간 경우) 에러 처리?
	memset(new, 0, sizeof(t_data));
	new->philosophers = ft_atoi(av[1]);
	new->die_t = ft_atoi(av[2]);
	new->eat_t = ft_atoi(av[3]);
	new->sleep_t = ft_atoi(av[4]);
	new->must_eat = -1;
	if (ac == 6)
		new->must_eat = ft_atoi(av[5]);
	if (new->philosophers < 1 || new->die_t < 0 || new->eat_t < 0 \
	|| new->sleep_t < 0 || (ac == 6 && new->must_eat < 0))
		return (ARG_ERR);
	new->forks = ft_calloc(new->philosophers, sizeof(int));
	if (new->forks == NULL)
		return (ARG_ERR);

// dead reset? >> 굳이 필요한지 다시 고민할 것, memset으로 했으면 밑에는 안해도 될듯?
	new->start = 0;
	new->end = 0;
	new->dead = 0;

	return (_init_mutex_data(new));
}

static int	_init_mutex_data(t_data *new)
{
	int	i;

	new->f_state = malloc(sizeof(pthread_mutex_t) * new->philosophers);
	if (new->f_state == NULL)
		return (MUTEX_ERR);
	i = 0;
	while (i < new->philosophers)
		if (pthread_mutex_init(&new->f_state[i++], NULL))
			return (MUTEX_ERR);
	if (pthread_mutex_init(&new->print, NULL) \
	|| pthread_mutex_init(&new->die_philo, NULL) \
	|| pthread_mutex_init(&new->end_philo, NULL))
		return (MUTEX_ERR);
	return (SUCCESS);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->philosophers);
	if (philo == NULL)
		return (NULL);		// because of return value is ptr*
	i = 0;
	while (i < data->philosophers)
	{
		philo[i].data = data;
		philo[i].id = i;
		philo[i].left = i;
		philo[i].right = (i + 1) % data->philosophers;
		philo[i].eat_cnt = 0;
		philo[i].full = FALSE;
		i++;
	}
	return (philo);
}
