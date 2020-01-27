/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 01:22:41 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 01:36:16 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_win_size(t_mlx *mlx, const char *str)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	mlx->win_width = ft_atoi(tmp [1]);
	mlx->win_height = ft_atoi(tmp [2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}

void	ft_get_floor_color(t_mlx *mlx, const char *str)
{
	char	**tmp;

	tmp = ft_split(str + 2, ',');
	mlx->map.f_color[0] = ft_atoi(tmp[0]);
	mlx->map.f_color[1] = ft_atoi(tmp[1]);
	mlx->map.f_color[2] = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}

void	ft_get_roof_color(t_mlx *mlx, const char *str)
{
	char	**tmp;

	tmp = ft_split(str + 2, ',');
	mlx->map.c_color[0] = ft_atoi(tmp[0]);
	mlx->map.c_color[1] = ft_atoi(tmp[1]);
	mlx->map.c_color[2] = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}

void	ft_parse_from_file(t_mlx *mlx, int map_fd)
{
	char	*str;

	while (get_next_line(map_fd, &str) > 0)
	{
		if (*str == 'R' && *(str + 1) == ' ')
			ft_get_win_size(mlx, str);
		else if (*str == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
			get_texture_n(mlx, str);
		else if (*str == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
			get_texture_s(mlx, str);
		else if (*str == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
			get_texture_w(mlx, str);
		else if (*str == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
			get_texture_e(mlx, str);
		else if (*str == 'S' && *(str + 1) == ' ')
			get_texture_sprite(mlx, str);
		else if (*str == 'F' && *(str + 1) == ' ')
			ft_get_floor_color(mlx, str);
		else if (*str == 'C' && *(str + 1) == ' ')
			ft_get_roof_color(mlx, str);
		free(str);
	}
	free(str);
}
