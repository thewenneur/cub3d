/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:14:55 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 01:32:21 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parser(char *filepath, t_mlx *mlx)
{
	int		map_fd;

	mlx->map.init = 1;
	if (!ft_strnstr(filepath, ".cub", ft_strlen(filepath))
	|| (map_fd = open(filepath, O_RDONLY)) == -1)
		mlx->map.init = 0;
	else
		ft_parse_from_file(mlx, map_fd);
	if (!mlx->win_height || !mlx->win_width || !mlx->map.n_texture.data
		|| !mlx->map.s_texture.data || !mlx->map.w_texture.data
		|| !mlx->map.e_texture.data || !mlx->map.sprite_texture.data)
		mlx->map.init = 0;
	return (mlx->map.init);
}
