/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:37:09 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 02:37:09 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	ft_mlx_init(int argc, char **argv)
{
	t_mlx	mlx;

	mlx = (t_mlx) {
			.mlx = mlx_init(),
			.save_path = ft_get_save_path(argc, argv),
			.img = (t_img) {},
			.map = (t_map) {
					.f_color[0] = -1,
					.f_color[1] = -1,
					.f_color[2] = -1,
					.c_color[0] = -1,
					.c_color[1] = -1,
					.c_color[2] = -1,
			}
	};
	if (argc < 2)
		ft_quit(&mlx);
	ft_parser(argv[1], &mlx);
	if (!mlx.mlx || !mlx.map.init)
		ft_quit(&mlx);
	mlx.img.data = mlx_xpm_file_to_image(mlx.mlx,
										 "/Users/tbrouill/Desktop/RWBY-7.XPM", &mlx.img.width, &mlx.img.height);
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_width, mlx.win_height, "RWBY");
	return (mlx);
}
