/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:40 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/26 14:07:16 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**split_command(t_pipe *p, char *cmd)
{
	char	**cmd_arr;

	cmd_arr = malloc(sizeof(char *) * (_cmd_arr_len(cmd) + 1));
	if (cmd_arr == NULL)
		exit (EXIT_FAILURE);
	return (cmd_arr);
}

static int	_cmd_arr_len(char *cmd)
{
	char	quote;
	int		space_end;	// space로 끝나지 않은 경우엔 cnt가 늘어나지 않는다
	int		cnt;

	cnt = 0;
	space_end = TRUE;
	while (*cmd)
	{
		if (*cmd != ' ')
		{
			if (space_end == TRUE)
				cnt++;
			if (_is_quote(*cmd, &quote) == TRUE)
			{
				cmd++;
				while (*cmd && *cmd != quote)
					cmd++;
				if (*cmd == NULL)
					exit (EXIT_FAILURE);	// dquote 상황은 error 처리
			}
			else	// 일반 문자열인 경우
				while (*cmd && _is_quote(*cmd, &quote) == FALSE && *cmd != ' ')
					cmd++;
			space_end = FALSE;
			continue ;
		}
		cmd++;
		space_end = TRUE;
	}
	return (cnt);
}

static int	_is_quote(char q, char *tmp_quote)
{
	if (q == '\'' || q == '\"')
	{
		*tmp_quote = q;
		return (TRUE);
	}
	return (FALSE);
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
