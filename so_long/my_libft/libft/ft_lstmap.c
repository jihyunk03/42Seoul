/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:14:40 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/24 21:36:59 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*t_res;
	void	*cnt;

	t_res = NULL;
	while (lst)
	{
		cnt = f(lst->content);
		if (!cnt)
		{
			ft_lstclear(&t_res, del);
			return (0);
		}
		node = ft_lstnew(cnt);
		if (!node)
		{
			del(cnt);
			ft_lstclear(&t_res, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&t_res, node);
	}
	return (t_res);
}
