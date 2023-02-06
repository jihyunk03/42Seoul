/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:05:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/06 13:31:12 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include "struct_info.h"

// split.c

// stack_init.c
t_stack	*stack_init(int len, char **data);
t_stack	*new_stack(void);
t_dll	*new_dll(int data);
void	dll_add_back(t_stack *new, t_dll *lst);

// free_all.c
void	*free_stack(t_stack *stack);
void	*free_arr(char **arr);

#endif
