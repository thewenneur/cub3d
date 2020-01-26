/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:04:02 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/02 20:51:07 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	c;

	if (!(memory = malloc(size * count)))
		return (NULL);
	c = -1;
	while ((unsigned long)(c -= -1) < size * count)
		*((char *)memory + c) = 0;
	return (memory);
}
