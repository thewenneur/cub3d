/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:01:13 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/13 16:04:03 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = -1;
	if (!(dest = ft_strdup(s)))
		return (NULL);
	while (dest[++i])
		dest[i] = (*f)(i, dest[i]);
	return (dest);
}
