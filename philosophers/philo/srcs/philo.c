/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:16:10 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/11 05:11:26 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_leaks(void);

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		errno;

	atexit(check_leaks);

	if (ac < 5 || ac > 6)
		return (error_message("Error: invalid arguments\n"));

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	errno = init_data(data, ac, av);
	if (errno != SUCCESS)
		return (error_exit(NULL, data, errno));
	philo = init_philo(data);
	if (philo == NULL)
		return (error_exit(NULL, data, ALLOC_FAIL));
	return (start_philo(philo, data));
}

void	check_leaks(void)
{
	system("leaks --quiet philo");
}
