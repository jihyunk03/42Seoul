/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:18:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/12 22:58:46 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	*line;

	if (ac == 1)
		return (0);
	a_stack = stack_init(av);
	b_stack = new_stack();
	if (a_stack == NULL || b_stack == NULL)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		find_command(a_stack, b_stack, line);
		free (line);
	}
	if (check_sort(a_stack, a_stack->size))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}

void	find_command(t_stack *a_stack, t_stack *b_stack, char *line)
{
	if (ft_strcmp(line, SA) == 0)
		swap(a_stack, 0);
	else if (ft_strcmp(line, SB) == 0)
		swap(b_stack, 0);
	else if (ft_strcmp(line, SS) == 0)
		swap_both(a_stack, b_stack, 0);
	else if (ft_strcmp(line, PA) == 0)
		push(b_stack, a_stack, 0);
	else if (ft_strcmp(line, PB) == 0)
		push(a_stack, b_stack, 0);
	else if (ft_strcmp(line, RA) == 0)
		rotate(a_stack, 0);
	else if (ft_strcmp(line, RB) == 0)
		rotate(b_stack, 0);
	else if (ft_strcmp(line, RR) == 0)
		rotate_both(a_stack, b_stack, 0);
	else if (ft_strcmp(line, RRA) == 0)
		rv_rotate(a_stack, 0);
	else if (ft_strcmp(line, RRB) == 0)
		rv_rotate(b_stack, 0);
	else if (ft_strcmp(line, RRR) == 0)
		rv_rotate_both(a_stack, b_stack, 0);
	else
		error_exit_checker(a_stack, b_stack, line);
}

void	error_exit_checker(t_stack *a_stack, t_stack *b_stack, char *line)
{
	free (a_stack);
	free (b_stack);
	free (line);
	ft_printf("Error\n");
	exit (1);
}
