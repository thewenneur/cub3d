/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:20:29 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/21 18:50:42 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i + ft_strlen((char *)needle) <= len && haystack[i])
	{
		if (!ft_strncmp((char *)&haystack[i], (char *)needle,
				ft_strlen((char *)needle)))
			return (((char *)haystack) + i);
		i++;
	}
	return (NULL);
}
