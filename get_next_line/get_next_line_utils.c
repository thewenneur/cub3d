/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:28:08 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 00:12:35 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_is_eol(char *tmp)
{
	char	*ptr;

	ptr = tmp;
	if (!tmp)
		return (ERROR);
	tmp--;
	while (*(++tmp))
		if (*tmp == '\n')
			return ((int)(tmp - ptr));
	return (ERROR);
}

int		ft_set_line(char **line, char **tmp, int ret)
{
	int		i;
	char	*old;

	if ((i = ft_is_eol(*tmp)) != ERROR)
	{
		*line = ft_substr(*tmp, 0, i);
		old = *tmp;
		*tmp = *tmp + i + 1;
		*tmp = ft_strdup(*tmp);
		free(old);
		return (NOT_EOF);
	}
	*line = ft_strdup(*tmp ? *tmp : "");
	ft_destroy(tmp);
	return (ret ? NOT_EOF : OK);
}

void	ft_destroy(char **trash)
{
	free(*trash);
	*trash = NULL;
}
