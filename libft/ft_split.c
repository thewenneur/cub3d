/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:55:00 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/28 13:53:47 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(const char *s, char sep)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i] && s[i] == sep)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != sep)
			i++;
		res++;
		while (s[i] && s[i] == sep)
			i++;
	}
	return (res);
}

static int		size_of_word(char const *s, char sep)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (++i);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_count;
	int		i;

	i = -1;
	word_count = ft_word_count((char *)s, c);
	if (!(tab = (char **)malloc((word_count + 1) * sizeof(char *))))
		return (NULL);
	while (++i < word_count)
	{
		while (s[0] && s[0] == c)
			s++;
		if (!(tab[i] = ft_substr(s, 0, size_of_word(s, c) - 1)))
		{
			while (i)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		s += size_of_word(s, c);
	}
	tab[word_count] = NULL;
	return (tab);
}
