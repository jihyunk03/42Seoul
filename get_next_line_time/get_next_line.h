/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:04:55 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/29 19:22:12 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef DEFAULT_SIZE
#  if BUFFER_SIZE < 1024
#   define DEFAULT_SIZE 1024
#  else
#   define DEFAULT_SIZE BUFFER_SIZE
#  endif
# endif

typedef struct s_list
{
	int				fd;
	char			*buff;
	size_t			len;
	size_t			b_size;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	*free_all(t_list **head, t_list *lst);
t_list	*gnl_lstnew(int new_fd);
size_t	check_newline(char *s);
char	*realloc_backup(t_list *lst);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
