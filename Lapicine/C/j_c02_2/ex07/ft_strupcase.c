/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:44:17 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/05 11:45:08 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (is_lowercase(str[index]))
			str[index] = str[index] - 'a' + 'A';
		index++;
	}
	return (str);
}
