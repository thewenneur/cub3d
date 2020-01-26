/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:14:49 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/18 01:34:50 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*dest;

	i = -1;
	s1_len = ft_strlen((char *)s1) - 1;
	s2_len = ft_strlen((char *)s2) - 1;
	if (s1 && s2)
	{
		if (!(dest = malloc(sizeof(char) * (s1_len + s2_len + 3))))
			return (NULL);
		while (++i <= (s1_len + s2_len + 1))
			dest[i] = i <= s1_len ? s1[i] : s2[i - (s1_len + 1)];
		dest[i] = '\0';
	}
	else if (s1)
		dest = ft_strdup(s1);
	else if (s2)
		dest = ft_strdup(s2);
	else
		return ("\0");
	return (dest);
}
