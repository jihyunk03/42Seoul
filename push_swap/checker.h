/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:19:15 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/12 23:09:10 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./my_libft/libft.h"
# include "./my_libft/ft_printf.h"
# include "./my_libft/get_next_line.h"
# include "struct_info.h"
# include "define_enum.h"

// checker.c
void	find_and_operate(t_stack *a_stack, t_stack *b_stack, char *line);
void	error_exit_checker(t_stack *a_stack, t_stack *b_stack, char *line);

// stack_init.c
t_stack	*stack_init(char **data);
t_stack	*new_stack(void);
t_dll	*new_dll(int data, int flag);

// stack_init_utils.c
int		push_to_stack(t_stack *new, char *data);
int		is_integer(char *s);
int		push_swap_atoi(const char *str, int *flag);
int		dll_add_back(t_stack *new, t_dll *lst);
void	index_init(t_stack *stack);

// free_all.c
void	*free_stack(t_stack *stack);
int		free_dll(t_dll *lst);
int		free_arr(char **arr);

// check_sort.c
int		check_sort(t_stack *stack, int size);

// operator.c
void	swap(t_stack *stack, char *op);
void	swap_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	do_swap(t_stack *stack);
void	push(t_stack *from, t_stack *to, char *op);
void	do_push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack, char *op);
void	rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	do_rotate(t_stack *stack);
void	rv_rotate(t_stack *stack, char *op);
void	rv_rotate_both(t_stack *a_stack, t_stack *b_stack, char *op);
void	do_rv_rotate(t_stack *stack);

#endif
