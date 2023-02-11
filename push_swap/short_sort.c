/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:07:14 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/11 15:33:55 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *a_stack, t_stack *b_stack)
{
	if (check_sort(a_stack, b_stack))
		return ;
	if (a_stack->size == 2)
		sa(a_stack);
	else if (a_stack->size == 3)
		sort_size_three(a_stack, b_stack);
	else if (a_stack->size == 4)
		sort_size_four(a_stack, b_stack);
	else if (a_stack->size == 5)
		sort_size_five(a_stack, b_stack);
}

void	sort_size_three(t_stack *a_stack, t_stack *b_stack)
{

}

void	sort_size_four(t_stack *a_stack, t_stack *b_stack)
{

}

void	sort_size_five(t_stack *a_stack, t_stack *b_stack)
{

}
