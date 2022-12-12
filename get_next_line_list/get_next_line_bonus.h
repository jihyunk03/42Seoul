/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:52:33 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/12 19:43:07 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

t_list	*find_fd(t_list **head, int fd_new);
size_t	check_newline(char *backup);
size_t	read_file(char **backup, int fd, char **buff, size_t gnl_len);
char	*save_for_next(char *backup, char **gnl, size_t gnl_len);

void	*free_all(t_list **head, t_list *lst);
t_list	*ft_lstnew(int fd_new);
size_t	ft_strlen(const char *s);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
