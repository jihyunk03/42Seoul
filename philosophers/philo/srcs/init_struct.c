/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:44:41 by jihykim2          #+#    #+#             */
/*   Updated: 2023/07/31 16:27:58 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_data(t_data *new, int ac, char **av)
{	// ft_atoi의 결과가 이상한 경우(숫자가 아닌 것이 들어간 경우) 에러 처리?
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
	return (IS_OK);
}

