/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:05 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 00:14:25 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H
# define ERROR -1
# define OK 0
# define NOT_EOF 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_list
{
	int				*fd;
	char			*tmp;
	struct s_list	*next;
}					t_list;
int					get_next_line(int fd, char **line);
void				ft_destroy(char **trash);
int					ft_set_line(char **line, char **tmp, int ret);
int					ft_is_eol(char *tmp);
#endif
