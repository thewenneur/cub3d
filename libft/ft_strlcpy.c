/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:59:57 by jgiron            #+#    #+#             */
/*   Updated: 2019/08/15 18:13:06 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int i;
	unsigned int length;

	length = 0;
	i = 0;
	while (i < size - 1 && src[i] != '\0' && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	while (*src != '\0')
	{
		length++;
		src++;
	}
	return (length);
}
