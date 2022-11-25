/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:00:24 by jihykim2          #+#    #+#             */
/*   Updated: 2022/11/22 13:15:48 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_new;

	t_new = (t_list *)malloc(sizeof(t_list));
	if (t_new == NULL)
		return (0);
	t_new->content = content;
	t_new->next = NULL;
	return (t_new);
}
