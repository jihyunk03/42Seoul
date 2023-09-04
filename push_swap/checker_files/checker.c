/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:18:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/16 05:04:53 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	*line;

	if (ac < 2)
		return (EXIT_SUCCESS);
	a_stack = stack_init(av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)
		return (free_for_exit(a_stack, b_stack, FALSE));
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (find_and_operate(a_stack, b_stack, line) == FALSE)
			return (error_exit_checker(a_stack, b_stack, line));
		free (line);
	}
	if (check_sort(a_stack, a_stack->size) && b_stack->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_for_exit(a_stack, b_stack, TRUE));
}

int	find_and_operate(t_stack *a_stack, t_stack *b_stack, char *line)
{
	if (ft_strcmp(line, SA) == 0)
		swap(a_stack, NOPRINT);
	else if (ft_strcmp(line, SB) == 0)
		swap(b_stack, NOPRINT);
	else if (ft_strcmp(line, SS) == 0)
		swap_both(a_stack, b_stack, NOPRINT);
	else if (ft_strcmp(line, PA) == 0)
		push(b_stack, a_stack, NOPRINT);
	else if (ft_strcmp(line, PB) == 0)
		push(a_stack, b_stack, NOPRINT);
	else if (ft_strcmp(line, RA) == 0)
		rotate(a_stack, NOPRINT);
	else if (ft_strcmp(line, RB) == 0)
		rotate(b_stack, NOPRINT);
	else if (ft_strcmp(line, RR) == 0)
		rotate_both(a_stack, b_stack, NOPRINT);
	else if (ft_strcmp(line, RRA) == 0)
		rv_rotate(a_stack, NOPRINT);
	else if (ft_strcmp(line, RRB) == 0)
		rv_rotate(b_stack, NOPRINT);
	else if (ft_strcmp(line, RRR) == 0)
		rv_rotate_both(a_stack, b_stack, NOPRINT);
	else
		return (FALSE);
	return (TRUE);
}

int	error_exit_checker(t_stack *a_stack, t_stack *b_stack, char *line)
{
	free_stack(a_stack);
	free_stack(b_stack);
	if (line)
		free (line);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}
