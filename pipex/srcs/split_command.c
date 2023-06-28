/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:40 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 22:39:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	_string_length(char **cmd, char *quote);
static char	*_make_string(char **cmd, char *string, int space_end);
static char *_join_string(char *string, char *_add);

void	split_command(t_pipe *p, char *cmd)
{
	int	space_end;
	int	i;

	p->cmd_args = malloc(sizeof(char *) * (cmd_args_len(cmd) + 1));
	if (p->cmd_args == NULL)
		exit (EXIT_FAILURE);
	space_end = TRUE;
	i = 0;
	while (*cmd)
	{
		if (*cmd != ' ')
		{	// 난 그냥 두가지로 나눠서 strjoin 할래ㅡㅡ 짜증나
			p->cmd_args[i] = _make_string(&cmd, p->cmd_args[i], space_end);
			if (*cmd != ' ')
				space_end = FALSE;
			else	// string이 끝났으므로 p->cmd_args의 index를 증가
				i++;
			continue ;
		}
		cmd++;
		space_end = TRUE;
	}
	if (space_end == FALSE)
		i++;
	p->cmd_args[i] = NULL;
}

static int	_string_length(char **cmd, char *quote)
{
	int		len;

	len = 0;
	*quote = 0;
	if (is_quote(**cmd, quote) == TRUE)
	{
		while (*(++(*cmd)) != *quote && ++len)
			if (**cmd == 0)
				exit (EXIT_FAILURE);
		(*cmd)++;
	}
	else
	{
		while (**cmd && is_quote(**cmd, quote) == FALSE && **cmd != ' ' \
				&& ++len)
			(*cmd)++;
		*quote = 0;
	}
	return (len);
}

static char	*_make_string(char **cmd, char *string, int space_end)
{
	char	*new_string;
	char	*copy_address;
	char	quote;
	int		len;

	copy_address = *cmd;
	len = _string_length(cmd, &quote);
	new_string = malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		exit (EXIT_FAILURE);
	if (quote != 0)
		copy_address++;
	ft_strlcpy(new_string, copy_address, len + 1);
	if (space_end == TRUE)
		return (new_string);
	return (_join_string(string, new_string));
}

static char *_join_string(char *string, char *_add)
{
	char	*new_string;

	new_string = ft_strjoin(string, _add);
	free (string);
	free (_add);
	if (new_string == NULL)
		exit (EXIT_FAILURE);
	return (new_string);
}
