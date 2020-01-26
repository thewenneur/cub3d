/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:50:44 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/29 17:40:51 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*wip;
	char	*src_str;

	if (!dst)
		return (NULL);
	i = 0;
	wip = dst;
	src_str = (char*)src;
	while (i < n)
	{
		wip[i] = src_str[i];
		i++;
	}
	dst = wip;
	return (dst);
}
