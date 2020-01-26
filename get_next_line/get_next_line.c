/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:20 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 00:28:28 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin2(char **s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*dest;

	i = -1;
	s1_len = (int)ft_strlen(*s1) - 1;
	s2_len = (int)ft_strlen(s2) - 1;
	if (*s1 && s2)
	{
		if (!(dest = malloc(sizeof(char) * (s1_len + s2_len + 3))))
			return (NULL);
		while (++i <= (s1_len + s2_len + 1))
			dest[i] = i <= s1_len ? (*s1)[i] : s2[i - (s1_len + 1)];
		dest[i] = '\0';
		free(*s1);
	}
	else if (*s1)
	{
		dest = ft_strdup(*s1);
		free(*s1);
	}
	else
		dest = ft_strdup(s2);
	return (dest);
}

static int	ft_init(int fd, char ***line, char **buff)
{
	if (!*line || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
	{
		*line = NULL;
		return (ERROR);
	}
	if (!(*buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ERROR);
	return (OK);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	char		*buff;
	int			ret;
	int			a;

	if (ft_init(fd, &line, &buff) == ERROR)
		return (ERROR);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin2(&tmp, buff);
		if (ft_is_eol(tmp) != ERROR)
			break ;
	}
	ft_destroy(&buff);
	if ((a = ft_set_line(line, &tmp, ret)) == OK)
		tmp = 0;
	return (a);
}
