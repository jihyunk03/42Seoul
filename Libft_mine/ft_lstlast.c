/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:03:26 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t_last;

	t_last = lst;
	while (t_last)
	{
		if (t_last->next == NULL)
			break ;
		t_last = t_last->next;
	}
	return (t_last);
}
