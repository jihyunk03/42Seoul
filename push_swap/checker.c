/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:18:50 by jihykim2          #+#    #+#             */
/*   Updated: 2023/02/12 19:28:34 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	*line;

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
		if (find_command(a_stack, b_stack, line))
		{
			free (line);
			break ;		// no check_sort!!!!!!!!!
		}
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

int	find_command(t_stack *a_stack, t_stack *b_stack, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		sa(a_stack);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		sb(b_stack);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ss(a_stack, b_stack);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		pa(b_stack, a_stack);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		pb(a_stack, b_stack);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ra(a_stack);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rb(b_stack);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(a_stack, b_stack);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rra(a_stack);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rrb(b_stack);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrr(a_stack, b_stack);
	else
		return (ft_printf("Error\n"));
	return (0);
}
