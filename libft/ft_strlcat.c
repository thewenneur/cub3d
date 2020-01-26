/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:18:32 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/02 20:58:30 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dest_l;
	size_t src_l;

	if (dst)
		dest_l = ft_strlen(dst);
	else
		dest_l = 0;
	src_l = ft_strlen((char *)src);
	i = -1;
	if (dstsize == 0)
		return (src_l);
	if (dstsize < dest_l)
		src_l += dstsize;
	else
		src_l += dest_l;
	while (src[++i] != '\0' && (dest_l + i) < dstsize - 1)
		dst[i + dest_l] = src[i];
	if (dstsize >= dest_l)
		dst[i + dest_l] = '\0';
	return (src_l);
}
