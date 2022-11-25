/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:51:02 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/05 11:52:43 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (is_uppercase(str[index]))
			str[index] = str[index] - 'A' + 'a';
		index++;
	}
	return (str);
}
