/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:40 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/23 17:33:14 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**split_command(t_pipe *p, char *cmd)
{
	char	**cmd_arr;

	if (cmd_arr == NULL)
		exit(EXIT_FAILURE);
	return (cmd_arr);
}

static int	_cmd_arr_len(char *cmd)
{
	char	quote;
	int		cnt;
	int		is_quote;

	cnt = 0;
	is_quote = 0;
	while (*cmd)
	{
		cnt++;
		if (_is_quote(*cmd) == SMALL_QUOTE)
		{
			cmd++;
			while (*cmd && *cmd)
			{

			}
		}
	}
}

static int	_is_quote(char q, char *tmp_quote)
{
	if (q == '\'' || q == '\"')
	{
		*tmp_quote = q;
		return (SMALL_QUOTE);
	}

}

/* // 초안(awk와 같은 명령어가 들어오지 않는 경우)
char	**split_command(t_pipe *p, char *cmd)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	if (cmd_arr == NULL)
		exit(EXIT_FAILURE);
	return (cmd_arr);
}
*/
