/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:27:51 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/18 04:51:18 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_delchar(char **dst, char sep)
{
	char	*ptr;

	while ((ptr = ft_strchr(*dst, sep)))
	{
		if (ft_strlen(ptr) > 1)
			ft_strlcpy(*dst, &ptr[1], ft_strlen(ptr));
		else
			(*dst)[0] = '\0';
	}
}

static	void	ft_loop1(char **dest, int *j, int *i, const char *set)
{
	int		char_found;

	while ((*dest)[++(*i)])
	{
		char_found = 0;
		*j = -1;
		while (set[++(*j)])
			if (ft_strchr(*dest, set[*j]) == &(*dest)[*i])
			{
				(*dest)[*i] = 27;
				char_found = 1;
			}
		if (!char_found)
			break ;
	}
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*dest;
	int		char_found;

	i = -1;
	if (!(dest = ft_strdup(s1)))
		return (NULL);
	ft_loop1(&dest, &j, &i, set);
	i = ft_strlen(dest);
	while (dest[--i])
	{
		char_found = 0;
		j = -1;
		while (set[++j] && !char_found)
			if (set[j] == dest[i])
			{
				char_found = 1;
				dest = ft_substr(dest, 0, i);
			}
		if (!char_found)
			break ;
	}
	ft_delchar(&dest, 27);
	return (dest);
}
