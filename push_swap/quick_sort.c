/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:17:16 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/10 11:37:51 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack *a_stack, t_stack *b_stack)
{
	t_cmd	*cmd;

	cmd = new_cmd();
	if (cmd == NULL)
		exit (1);	// error code(later)
}

t_cmd	*new_cmd(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	new->cnt = 0;
	new->cmd = malloc(sizeof(char) * 200000);
	if (cmd == NULL)
	{
		free (new);
		return (NULL);
	}
	return (new);
}
