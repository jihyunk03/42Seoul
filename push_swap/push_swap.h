/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:05:43 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/07 00:13:22 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include "struct_info.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

// stack_init.c
t_stack	*stack_init(char **data);
t_stack	*new_stack(void);
t_dll	*new_dll(int data, int flag);

// stack_init_utils.c
int		push_to_stack(t_stack *new, char *data);
int		is_integer(char *s);
int		push_swap_atoi(const char *str, int *flag);
void	dll_add_back(t_stack *new, t_dll *lst);
int		check_and_init(t_stack *stack);

// free_all.c
void	*free_stack(t_stack *stack);
int		free_arr(char **arr);

// libft prototypes for test & check leaks => must remove!!
void 	check_leak(void);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);

#endif
