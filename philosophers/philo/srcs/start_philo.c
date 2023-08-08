/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:13:56 by jihykim2          #+#    #+#             */
/*   Updated: 2023/08/08 18:47:46 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*_start_routine(void *ph);

int	start_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = init_philo(data);
	if (philo == NULL)
		return (PHILO_ERR);		// 여기서는 philo가 생성되지 않음 >> data_err
	i = 0;
	while (i < data->philosophers)
	{
		if (pthread_create(&philo[i].tid, NULL, _start_routine, &philo[i]) != 0)
			return (PHILO_ERR);		// philo가 생성되어 있는 상태.. (따로 에러처리)
		i++;
	}
}

static void	*_start_routine(void *ph)
{
	t_philo	*philo;

	philo = ph;

}
