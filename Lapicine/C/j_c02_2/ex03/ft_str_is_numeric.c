/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:24:50 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 12:08:57 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!(is_number(str[index])))
			return (0);
		index++;
	}
	return (1);
}
