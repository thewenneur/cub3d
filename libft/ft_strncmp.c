/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:37:10 by jgiron            #+#    #+#             */
/*   Updated: 2019/11/13 15:26:19 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*s1 != *s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
