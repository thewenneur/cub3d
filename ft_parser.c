/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:14:55 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 01:36:16 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parser(char *filepath, t_app *app)
{
	int		map_fd;

	app->map.init = 1;
	if (!ft_strnstr(filepath, ".cub", ft_strlen(filepath))
	|| (map_fd = open(filepath, O_RDONLY)) == -1)
		app->map.init = 0;
	else
		ft_parse_from_file(app, map_fd);
	app->player = app->map.player_start;
	return (app->map.init);
}
