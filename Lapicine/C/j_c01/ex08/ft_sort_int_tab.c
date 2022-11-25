/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:59:55 by jihykim2          #+#    #+#             */
/*   Updated: 2022/08/29 13:01:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	while (i < size)
	{
		index = i;
		min = i;
		while (index < size)
		{
			if (tab[index] <= tab[min])
				min = index;
			index++;
		}
		ft_swap(tab + i, tab + min);
		i++;
	}
}
