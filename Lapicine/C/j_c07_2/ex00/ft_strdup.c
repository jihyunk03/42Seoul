/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:36:18 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/12 16:25:09 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	cnt;

	cnt = 0;
	while (src[cnt])
		cnt++;
	return (cnt);
}

void	ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	ft_strcpy(ptr, src);
	return (ptr);
}
