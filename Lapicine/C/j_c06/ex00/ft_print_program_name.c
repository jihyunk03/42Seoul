/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:24:04 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/08 20:42:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	idx;

	(void)ac;
	idx = 0;
	while (av[0][idx])
	{
		write(1, &av[0][idx], 1);
		idx++;
	}
	write(1, "\n", 1);
	return (0);
}
