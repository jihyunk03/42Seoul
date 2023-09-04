/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:29:00 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/29 07:08:47 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_includes/pipex_bonus.h"

static void	_is_in_string(char **cmd);

int	cmd_args_len(char *cmd)
{
	int		space_end;
	int		cnt;

	cnt = 0;
	space_end = TRUE;
	while (*cmd)
	{
		if (*cmd != ' ')
		{
			if (space_end == TRUE)
				cnt++;
			_is_in_string(&cmd);
			if (*cmd != ' ')
				space_end = FALSE;
			continue ;
		}
		cmd++;
		space_end = TRUE;
	}
	return (cnt);
}

int	is_quote(char q, char *tmp_quote)
{
	if (q == '\'' || q == '\"')
	{
		*tmp_quote = q;
		return (TRUE);
	}
	return (FALSE);
}

static void	_is_in_string(char **cmd)
{
	char	quote;

	quote = 0;
	if (is_quote(**cmd, &quote) == TRUE)
	{
		while (*(++(*cmd)) != quote)
			if (**cmd == 0)
				exit (EXIT_FAILURE);
		(*cmd)++;
	}
	else
		while (**cmd && is_quote(**cmd, &quote) == FALSE && **cmd != ' ')
			(*cmd)++;
}
