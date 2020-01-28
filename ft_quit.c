/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:09:48 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 05:49:39 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_quit(t_app *app)
{
	int	i;

	i = -1;
	if (app->mlx && app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->save_path)
		free(app->save_path);
	while (app->map.map_grid[++i])
		free(app->map.map_grid[i]);
	if (app->error)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd(app->error, 1);
		free(app->error);
	}
	else if (errno)
		perror("Error\n");
	exit(errno);
}
