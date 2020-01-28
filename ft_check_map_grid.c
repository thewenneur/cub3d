/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:11:45 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 04:47:36 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_check_map_grid_player_start(t_app *app, unsigned int x,
									   unsigned int y)
{
	if (app->map.map_grid[y][x] == 'N')
	{
		app->map.player_start.dir = 0.0;
		app->map.player_start.x = x;
		app->map.player_start.y = y;
		app->map.map_grid[y][x] = '0';
	}
	else if (app->map.map_grid[y][x] == 'S')
	{
		app->map.player_start.dir = 180.0;
		app->map.player_start.x = x;
		app->map.player_start.y = y;
		app->map.map_grid[y][x] = '0';
	}
	else if (app->map.map_grid[y][x] == 'E')
	{
		app->map.player_start.dir = 275.0;
		app->map.player_start.x = x;
		app->map.player_start.y = y;
		app->map.map_grid[y][x] = '0';
	}
	else if (app->map.map_grid[y][x] == 'W')
	{
		app->map.player_start.dir = 90.0;
		app->map.player_start.x = x;
		app->map.player_start.y = y;
		app->map.map_grid[y][x] = '0';
	}
}

void	ft_check_map_grid(t_app *app)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	x_max;
	unsigned int	y_max;
	unsigned int	len;

	y = -1;
	x_max = 0;
	y_max = 0;
	while (app->map.map_grid[y_max])
		y_max++;
	while (++y < y_max)
	{
		x = -1;
		if ((len = ft_strlen(app->map.map_grid[y])) > x_max)
			x_max = len;
		while (++x < len)
			ft_check_map_grid_player_start(app, x, y);
//		if (!y)
//		{
//			while (--x)
//				if (app->map.map_grid[0][x] != '1')
//					ft_init_error(app, "Map not closed");
//		}
	}

}


