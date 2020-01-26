/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:22:00 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/18 00:50:13 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		i_max;

	i = -1;
	i_max = ft_strlen((char *)s1) + 1;
	if (!(s2 = malloc(sizeof(char) * i_max)))
		return (NULL);
	while (++i < i_max)
		s2[i] = s1[i];
	return (s2);
}
