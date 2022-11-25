/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:01:19 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/03 21:57:51 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;
	int	count;

	idx = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[idx])
	{
		if (str[idx] == to_find[0])
		{
			count = 0;
			while (to_find[count] && str[idx + count] == to_find[count])
				count++;
			if (count == ft_strlen(to_find))
				return (str + idx);
		}
		idx++;
	}
	return (0);
}
