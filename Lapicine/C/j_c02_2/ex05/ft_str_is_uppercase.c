/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:34:13 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 12:18:25 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!is_upper(str[index]))
			return (0);
		index++;
	}
	return (1);
}
