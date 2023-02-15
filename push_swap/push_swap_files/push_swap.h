/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:05:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 19:51:02 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./my_libft/libft.h"
# include "./my_libft/ft_printf.h"
# include "struct_info.h"
# include "define_enum.h"

t_stack	*stack_init(char **data);
t_stack	*new_stack(void);
int		push_to_stack(t_stack *new, char *data);

int		check_sort(t_stack *stack, int size);
void	short_sort(t_stack *a_stack, t_stack *b_stack);

void	a_sort_to_b(t_stack *a_stack, t_stack *b_stack);
void	b_sort_to_a(t_stack *a_stack, t_stack *b_stack);

void	swap(t_stack *stack, char *op);
void	swap_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	push(t_stack *from, t_stack *to, char *op);
void	rotate(t_stack *stack, char *op);
void	rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	rv_rotate(t_stack *stack, char *op);
void	rv_rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);

int		free_for_exit(t_stack *a_stack, t_stack *b_stack, int errorno);
void	*free_stack(t_stack *stack);
int		free_dll(t_dll *lst);
int		free_arr(char **arr);

#endif
