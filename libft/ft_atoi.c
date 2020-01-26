/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:43:12 by tbrouill          #+#    #+#             */
/*   Updated: 2019/11/28 13:53:47 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int	start;
	int result;

	result = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
											|| str[i] == '\f' || str[i] == ' ')
		i++;
	start = i;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((str[start] == '-') ? result * -1 : result);
}
