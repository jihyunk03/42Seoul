/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:09:30 by jihykim2          #+#    #+#             */
/*   Updated: 2022/09/06 13:11:01 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add_print(void *address, int i)
{
	long long	ptr;

	ptr = (long long)address;
	if (i < 16)
	{
		add_print((void *)(ptr / 16), i + 1);
		write(1, &"0123456789abcdef"[ptr % 16], 1);
	}
}

void	hex_print(unsigned char *str, unsigned int idx, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (str[idx] && i < 16 && idx < size)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[str[idx] / 16], 1);
		write(1, &"0123456789abcdef"[str[idx] % 16], 1);
		idx++;
		i++;
	}
	while (i < 16)
	{
		if (idx % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		idx++;
		i++;
	}
}

void	cha_print(unsigned char *str, unsigned int idx, unsigned int size)
{
	unsigned int	i;

	i = 0;
	write(1, " ", 1);
	while (str[idx] && i < 16 && idx < size)
	{
		if (!(str[idx] >= ' ' && str[idx] <= '~'))
			write(1, ".", 1);
		else
			write(1, str + idx, 1);
		idx++;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size)
	{
		add_print(&addr[idx], 0);
		write(1, ":", 1);
		hex_print((unsigned char *)addr, idx, size);
		cha_print((unsigned char *)addr, idx, size);
		write(1, "\n", 1);
		idx += 16;
	}
	return (addr);
}
