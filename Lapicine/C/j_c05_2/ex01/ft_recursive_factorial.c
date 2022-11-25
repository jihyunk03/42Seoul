/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:56:16 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/08 16:29:43 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb >= 0)
	{
		if (nb == 0 || nb == 1)
			return (1);
		return (nb * ft_recursive_factorial(nb - 1));
	}
	return (0);
}
