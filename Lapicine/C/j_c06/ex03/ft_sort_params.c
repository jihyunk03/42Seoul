/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:05:24 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/08 21:36:17 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	main(int ac, char *av[])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (++i < ac)
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) > 0)
				ft_swap(&av[i], &av[j]);
			j++;
		}
		k = 0;
		while (av[i][k])
		{
			write(1, &av[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
