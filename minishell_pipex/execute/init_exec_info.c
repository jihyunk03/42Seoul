/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:40:35 by jihykim2          #+#    #+#             */
/*   Updated: 2023/09/02 20:50:18 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_exec/execute.h"

t_exec_info	*init_exec_info(t_shell_info *parse)
{
	t_exec_info	*exec;

	exec = malloc(sizeof(t_exec_info));
	if (exec == NULL)
		exit (EXIT_FAILURE);

}
