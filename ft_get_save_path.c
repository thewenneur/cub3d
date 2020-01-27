/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_save_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:05:05 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 02:16:56 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_save_path(int argc, char **argv)
{
	char	*ret;
	char	*tmp;

	if (argc >= 4 && ft_strncmp(argv[1], "--save", 6))
	{
		tmp = ft_substr(argv[3], ft_strlen(argv[3]) - 4, 4);
		if (ft_strncmp(tmp, ".bmp", 4))
			ret = ft_strjoin(argv[3], ".bmp");
		else
			ret = ft_strdup(argv[3]);
		free(tmp);
	}
	else
		ret = NULL;
	return (ret);
}