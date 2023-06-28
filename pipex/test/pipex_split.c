/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:43:40 by jihykim2          #+#    #+#             */
/*   Updated: 2023/06/28 19:06:46 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_test.h"

static int	_cmd_arr_len(char *cmd);
static void	_is_in_string(char **cmd);
static int	_is_quote(char q, char *tmp_quote);
static int	_string_length(char **cmd, char *quote);
static char	*_make_string(char **cmd);
static char *_join_string(char **cmd, char *string);

char	**split_command(char *cmd)
{
	char	**cmd_arr;
	int		space_end;
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
				cmd_arr[i] = _make_string(&cmd);
			else
				cmd_arr[i] = _join_string(&cmd, cmd_arr[i]);
			if (*cmd != ' ')
				space_end = FALSE;
			else	// string이 끝났으므로 cmd_arr의 index를 증가
				i++;
			continue ;
		}
		cmd++;
		space_end = TRUE;
	}
	if (space_end == FALSE)
		i++;
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

	len = 0;
	if (_is_quote(**cmd, quote) == TRUE)
	{
		while (*(++(*cmd)) != *quote && ++len)
			if (**cmd == 0)
				exit (EXIT_FAILURE);
		(*cmd)++;
	}
	else
	{
		while (**cmd && _is_quote(**cmd, quote) == FALSE && **cmd != ' ' \
				&& ++len)
			(*cmd)++;
		*quote = 0;
	}
	return (len);
}

static char	*_make_string(char **cmd)
{
	char	*string;
	char	*copy_address;
	char	quote;
	int		len;

	copy_address = *cmd;
	quote = 0;
	len = _string_length(cmd, &quote);
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		exit (EXIT_FAILURE);
	if (quote != 0)
		copy_address++;
	ft_strlcpy(string, copy_address, len + 1);
	return (string);

}

static char *_join_string(char **cmd, char *string)
{
	char	*new_string;
	char	*tmp;

	tmp = _make_string(cmd);
	new_string = ft_strjoin(string, tmp);
	free (string);
	free (tmp);
	if (new_string == NULL)
		exit (EXIT_FAILURE);
	return (new_string);
}



// 확인용 main문
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("no args\n\n");
		return (EXIT_FAILURE);
	}

/*	// 원래 버전
	char	**string_arr = split_command(av[1]);
	int		len = _cmd_arr_len(av[1]);

	printf("cmd: %s\n", av[1]);
	printf("cmd length: %d\n\n", len);
	for (int i = 0; i < len + 1; i++)
		printf("cmd[%d]: %s\n", i, string_arr[i]);
*/
	// 다른 버전
	char	*string = "";
	char	*tmp;
	char	*tmp2;
	for (int i = 1; i < ac; i++)
	{
		tmp = string;
		string = ft_strjoin(string, av[i]);
		if (i != 1)
			free (tmp);
		tmp2 = string;
		if (i < ac - 1)
		{
			string = ft_strjoin(string, " ");
			free (tmp2);
		}
	}
	printf("cmd: %s\n", string);

	char	**string_arr = split_command(string);
	int		len = _cmd_arr_len(string);

	printf("cmd length: %d\n\n", len);
	for (int i = 0; i < len + 1; i++)
		printf("cmd[%d]: %s\n", i, string_arr[i]);
	return (EXIT_SUCCESS);
}
