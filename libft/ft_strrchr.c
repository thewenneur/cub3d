/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:47:53 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/14 16:57:45 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int buff;

	i = -1;
	buff = -1;
	while (s[++i])
	{
		if ((char)s[i] == (char)c)
			buff = i;
	}
	if ((char)s[i] == (char)c)
		buff = i;
	if (buff != -1)
		return ((char *)s + buff);
	return (NULL);
}
