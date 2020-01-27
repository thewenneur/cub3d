/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:54:05 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 06:00:28 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_get_win_size(t_mlx *mlx, const char *str)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	mlx->win_width = ft_atoi(tmp [1]);
	mlx->win_height = ft_atoi(tmp [2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	if (!mlx->win_width || !mlx->win_height)
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't parse the resolution (R) parameter");
	}
}

void		ft_get_floor_color(t_mlx *mlx, const char *str)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(str + 2, ',');
	while (tmp[++i])
	{
		mlx->map.f_color[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	if (mlx->map.f_color[0] == -1 || mlx->map.f_color[1] == -1
	|| mlx->map.f_color[2] == -1 || tmp[i])
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't parse the floor color (F) parameter");
	}
	free(tmp);
}

void		ft_get_roof_color(t_mlx *mlx, const char *str)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(str + 2, ',');
	while (tmp[++i] && i < 3)
	{
		mlx->map.c_color[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	if (mlx->map.c_color[0] == -1 || mlx->map.c_color[1] == -1
		|| mlx->map.c_color[2] == -1 || tmp[i])
	{
		mlx->map.init = 0;
		mlx->error = ft_strdup("Couldn't parse the roof color (C) parameter");
	}
	free(tmp);
}

static void	ft_parse_line_from_file(t_mlx *mlx, char **str, int map_fd)
{
	if (**str == 'R' && *((*str) + 1) == ' ')
		ft_get_win_size(mlx, *str);
	else if (**str == 'N' && *((*str) + 1) == 'O' && *((*str) + 2) == ' ')
		get_texture_n(mlx, *str);
	else if (**str == 'S' && *((*str) + 1) == 'O' && *((*str) + 2) == ' ')
		get_texture_s(mlx, *str);
	else if (**str == 'W' && *((*str) + 1) == 'E' && *((*str) + 2) == ' ')
		get_texture_w(mlx, *str);
	else if (**str == 'E' && *((*str) + 1) == 'A' && *((*str) + 2) == ' ')
		get_texture_e(mlx, *str);
	else if (**str == 'S' && *((*str) + 1) == ' ')
		get_texture_sprite(mlx, *str);
	else if (**str == 'F' && *((*str) + 1) == ' ')
		ft_get_floor_color(mlx, *str);
	else if (**str == 'C' && *((*str) + 1) == ' ')
		ft_get_roof_color(mlx, *str);
	else if (**str)
		ft_get_map_grid(mlx, str, map_fd);
	if (*str)
		free(*str);
}

void		ft_parse_from_file(t_mlx *mlx, int map_fd)
{
	char	*str;

	while (get_next_line(map_fd, &str) > 0)
		ft_parse_line_from_file(mlx, &str, map_fd);
	ft_parse_line_from_file(mlx, &str, map_fd);
//	mlx->player = (t_player) {
//		.dir = mlx->map.player_start.dir,
//		.x = mlx->map.player_start.x,
//		.y = mlx->map.player_start.y
//	};
}
