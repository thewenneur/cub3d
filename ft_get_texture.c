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

void get_texture_n(t_mlx *mlx, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	mlx->map.n_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
		&mlx->map.n_texture.width, &mlx->map.n_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!mlx->map.n_texture.data)
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't open the North Wall (NO) Texture.");
	}
}

void get_texture_s(t_mlx *mlx, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	mlx->map.s_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
		&mlx->map.s_texture.width, &mlx->map.s_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!mlx->map.s_texture.data)
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't open the South Wall (SO) Texture.");
	}
}

void get_texture_w(t_mlx *mlx, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	mlx->map.w_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
		&mlx->map.w_texture.width, &mlx->map.w_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!mlx->map.w_texture.data)
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't open the West Wall (WE) Texture.");
	}
}

void get_texture_e(t_mlx *mlx, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	mlx->map.e_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
		&mlx->map.e_texture.width, &mlx->map.e_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!mlx->map.e_texture.data)
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't open the East Wall (EA) Texture.");
	}
}

void get_texture_sprite(t_mlx *mlx, char *str)
{
	char **tmp;

	tmp = ft_split(str, ' ');
	mlx->map.sprite_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
		&mlx->map.sprite_texture.width, &mlx->map.sprite_texture.height);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	if (!mlx->map.sprite_texture.data)
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't open the sprite (S) Texture.");
	}
}