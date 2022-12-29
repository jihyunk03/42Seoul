/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:17 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/24 17:31:32 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*p_save;

	p = *lst;
	while (p)
	{
		p_save = p->next;
		(*del)(p->content);
		free(p);
		p = p_save;
	}
	*lst = NULL;
}
