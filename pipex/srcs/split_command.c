/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:40 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 17:10:33 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	_cmd_arr_len(char *cmd);
static void	_is_in_string(char **cmd);
static int	_is_quote(char q, char *tmp_quote);
static int	_string_length(char **cmd, char *quote);

char	**split_command(t_pipe *p, char *cmd)
{
	char	**cmd_arr;
	int		space_end;
	int		str_len;
	int		i;

	cmd_arr = malloc(sizeof(char *) * (_cmd_arr_len(cmd) + 1));
	if (cmd_arr == NULL)
		exit (EXIT_FAILURE);
	space_end = TRUE;
	i = 0;
	while (*cmd)
	{
		if (*cmd != ' ')
		{	// 난 그냥 두가지로 나눠서 strjoin 할래ㅡㅡ 짜증나
			if (space_end == TRUE)
				str_len = _string_length(&cmd);
			else
				str_len += _string_length(&cmd);
			if (*cmd != ' ')	// 해당 경우에만 i++ (string이 끝났기 때문)
				space_end = FALSE;
			else
			{
				cmd_arr[i] = malloc(sizeof(char) * (str_len + 1));
				ft_strlcpy(cmd_arr, cmd - str_len, str_len + 1);
				// 해당 quote 값을 strim으로 뺀다^^
				// 응 아니 난 strjoin으로 할래~
			}
			continue ;
		}
		cmd++;
		str_len = 0;
		space_end = TRUE;
	}
	cmd_arr[i] = NULL;
	return (cmd_arr);
}


static int	_cmd_arr_len(char *cmd)
{
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

static void	_is_in_string(char **cmd)
{
	char	quote;

	quote = 0;
	if (_is_quote(**cmd, &quote) == TRUE)
	{
		while (*(++(*cmd)) != quote)
			if (**cmd == 0)
				exit (EXIT_FAILURE);	// quote 상황은 exit_fail
		(*cmd)++;
	}
	else	// 일반 문자열인 경우
		while (**cmd && _is_quote(**cmd, &quote) == FALSE && **cmd != ' ')
			(*cmd)++;
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

static int	_string_length(char **cmd, char *quote)	// quote를 제외한 string의 개수!!
{
	int		len;

	*quote = 0;
	len = 0;
	if (_is_quote(**cmd, quote) == TRUE)
	{
		(*cmd)++;
		while (*(*cmd)++ != *quote && ++len)
			if (**cmd == 0)
				exit (EXIT_FAILURE);
	}
	else
		while (**cmd && _is_quote(**cmd, quote) == FALSE && **cmd != ' ' \
				&& ++len)
			(*cmd)++;
	return (len);
}

static char	*_make_string(char **cmd)
{
	char	*string;
	char	quote;

	string = malloc(sizeof(char) * (_string_length(cmd, &quote) + 1));
	if (string == NULL)
		exit (EXIT_FAILURE);

}

static char *_join_string(char **cmd, char *string)
{

}



// 확인용 main문
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 1)
		return (EXIT_FAILURE);
	printf("[%s]: %d\n", av[ac - 1], _cmd_arr_len(av[ac - 1]));

	char *s = "hello";
	char **arr = &s;
	while (*(++(*arr)))
		printf("%c", **arr);
}
