/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:30:14 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 12:14:06 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!is_lowercase(str[index]))
			return (0);
		index++;
	}
	return (1);
}
