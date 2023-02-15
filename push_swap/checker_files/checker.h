/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:19:15 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/15 19:52:39 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./my_libft/libft.h"
# include "./my_libft/ft_printf.h"
# include "./my_libft/get_next_line.h"
# include "struct_info.h"
# include "define_enum.h"

int		find_and_operate(t_stack *a_stack, t_stack *b_stack, char *line);
int		error_exit_checker(t_stack *a_stack, t_stack *b_stack, char *line);

t_stack	*stack_init(char **data);
t_stack	*new_stack(void);
int		push_to_stack(t_stack *new, char *data);

int		check_sort(t_stack *stack, int size);

void	swap(t_stack *stack, char *op);
void	swap_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	push(t_stack *from, t_stack *to, char *op);
void	rotate(t_stack *stack, char *op);
void	rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	rv_rotate(t_stack *stack, char *op);
void	rv_rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);

// remove!!!!!!!!!!!
void	check_stack_idx(t_stack *stack);
void	check_leak(void);

int		free_for_exit(t_stack *a_stack, t_stack *b_stack, int errorno);
void	*free_stack(t_stack *stack);
int		free_dll(t_dll *lst);
int		free_arr(char **arr);

#endif
