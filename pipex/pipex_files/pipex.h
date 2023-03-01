/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:52:12 by jihykim2          #+#    #+#             */
/*   Updated: 2023/03/02 00:35:12 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../my_libft/libft.h"
# include "../my_libft/ft_printf.h"
# include "../my_libft/get_next_line.h"
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

typedef struct s_args
{
	int		high;
	int		length;
	char	**arr;
}	t_args;

#endif
