/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:15:55 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/04 13:01:51 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (s1[idx] && s2[idx] && (idx < n - 1))
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	return (s1[idx] - s2[idx]);
}
