/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:50:44 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/29 17:46:08 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str;

	if (!dst && !src)
		return (NULL);
	str = dst;
	i = -1;
	if (((dst - src) <= (int)len) && ((dst - src) > 0))
	{
		i = len;
		while (--i + 1 > 0)
			*(str + i) = *(char *)(src + i);
		return (dst);
	}
	else
	{
		while (++i < len)
			*(str + i) = *(char *)(src + i);
		return (dst);
	}
}
