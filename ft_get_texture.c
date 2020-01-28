/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 01:13:04 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 02:31:24 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_texture_n(t_app *app, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	app->map.n_texture.data = mlx_xpm_file_to_image(app->mlx, tmp[1],
		&app->map.n_texture.width, &app->map.n_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!app->map.n_texture.data)
	{
		app->map.init = 0;
		app->error = ft_strdup("Couldn't open the North Wall (NO) Texture.");
	}
}

void get_texture_s(t_app *app, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	app->map.s_texture.data = mlx_xpm_file_to_image(app->mlx, tmp[1],
		&app->map.s_texture.width, &app->map.s_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!app->map.s_texture.data)
	{
		app->map.init = 0;
		app->error = ft_strdup("Couldn't open the South Wall (SO) Texture.");
	}
}

void get_texture_w(t_app *app, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	app->map.w_texture.data = mlx_xpm_file_to_image(app->mlx, tmp[1],
		&app->map.w_texture.width, &app->map.w_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!app->map.w_texture.data)
	{
		app->map.init = 0;
		app->error = ft_strdup("Couldn't open the West Wall (WE) Texture.");
	}
}

void get_texture_e(t_app *app, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	app->map.e_texture.data = mlx_xpm_file_to_image(app->mlx, tmp[1],
		&app->map.e_texture.width, &app->map.e_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!app->map.e_texture.data)
	{
		app->map.init = 0;
		app->error = ft_strdup("Couldn't open the East Wall (EA) Texture.");
	}
}

void get_texture_sprite(t_app *app, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	app->map.sprite_texture.data = mlx_xpm_file_to_image(app->mlx, tmp[1],
		&app->map.sprite_texture.width, &app->map.sprite_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!app->map.sprite_texture.data)
	{
		app->map.init = 0;
		app->error = ft_strdup("Couldn't open the sprite (S) Texture.");
	}
}