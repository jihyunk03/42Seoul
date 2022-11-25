/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:57:05 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/05 16:57:50 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_string(char c)
{
	if (c >= '0' && c <= '9')
		return (3);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	if (is_string(str[0]) == 1)
		str[0] = str[0] - 'a' + 'A';
	while (str[++idx])
	{
		if (is_string(str[idx]))
		{
			if (!is_string(str[idx - 1]) && is_string(str[idx]) == 1)
				str[idx] = str[idx] - 'a' + 'A';
			else if (is_string(str[idx - 1]) && is_string(str[idx]) == 2)
				str[idx] = str[idx] - 'A' + 'a';
		}
	}
	return (str);
}
