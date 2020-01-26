/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:50:44 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/28 14:10:22 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*wip;
	unsigned char	*src_str;

	i = -1;
	wip = dst;
	src_str = (unsigned char*)src;
	while (++i < n)
	{
		wip[i] = src_str[i];
		if (src_str[i] == (unsigned char)c)
		{
			dst = wip;
			return (&(dst[++i]));
		}
	}
	return (NULL);
}
