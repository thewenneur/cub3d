/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:14:55 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 00:46:42 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parser(char *filepath, t_mlx *mlx)
{
	int		map_fd;
	char	*str;
	char	**tmp;

	mlx->map.init = 1;
	if (!ft_strnstr(filepath, ".cub", ft_strlen(filepath))
	|| (map_fd = open(filepath, O_RDONLY)) == -1)
		mlx->map.init = 0;
	else
	{
		while (get_next_line(map_fd, &str) > 0)
		{
			if (*str == 'R' && *(str + 1) == ' ')
			{
				tmp = ft_split(str, ' ');
				mlx->win_width = ft_atoi(tmp [1]);
				mlx->win_height = ft_atoi(tmp [2]);
				free(tmp);
			}
			else if (*str == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
			{
				tmp = ft_split(str, ' ');
				mlx->map.n_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
					&mlx->map.n_texture.width, &mlx->map.n_texture.height);
				free(tmp);
			}
			else if (*str == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
			{
				tmp = ft_split(str, ' ');
				mlx->map.s_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
					&mlx->map.s_texture.width, &mlx->map.s_texture.height);
				free(tmp);
			}
			else if (*str == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
			{
				tmp = ft_split(str, ' ');
				mlx->map.w_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
					&mlx->map.w_texture.width, &mlx->map.w_texture.height);
				free(tmp);
			}
			else if (*str == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
			{
				tmp = ft_split(str, ' ');
				mlx->map.e_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
					&mlx->map.e_texture.width, &mlx->map.e_texture.height);
				free(tmp);
			}
			else if (*str == 'S' && *(str + 1) == ' ')
			{
				tmp = ft_split(str, ' ');
				mlx->map.sprite_texture.data = mlx_xpm_file_to_image(mlx->mlx, tmp[1],
					&mlx->map.sprite_texture.width,
					&mlx->map.sprite_texture.height);
				free(tmp);
			}
			else if (*str == 'F' && *(str + 1) == ' ')
			{
				tmp = ft_split(str + 2, ',');
				mlx->map.f_color[0] = ft_atoi(tmp[0]);
				mlx->map.f_color[1] = ft_atoi(tmp[1]);
				mlx->map.f_color[2] = ft_atoi(tmp[2]);
				free(tmp);
			}
			else if (*str == 'C' && *(str + 1) == ' ')
			{
				tmp = ft_split(str + 2, ',');
				mlx->map.c_color[0] = ft_atoi(tmp[0]);
				mlx->map.c_color[1] = ft_atoi(tmp[1]);
				mlx->map.c_color[2] = ft_atoi(tmp[2]);
				free(tmp);
			}
			free(str);
		}

	}
	if (!mlx->win_height || !mlx->win_width || !mlx->map.n_texture.data
		|| !mlx->map.s_texture.data || !mlx->map.w_texture.data
		|| !mlx->map.e_texture.data || !mlx->map.sprite_texture.data)
		mlx->map.init = 0;
	return (mlx->map.init);
}