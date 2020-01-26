/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:39:00 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/18 01:12:46 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	int	len;

	len = n < 0 ? 2 : 1;
	while (!(n > -10 && n < 10))
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	i;
	size_t	len;

	len = ft_nbrlen(n);
	i = 1;
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	result[len - i++] = 48 + n % 10;
	while ((n /= 10) > 0)
		result[len - i++] = 48 + n % 10;
	result[len] = '\0';
	return (result);
}
