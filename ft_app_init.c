/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:37:09 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 19:59:51 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_app	ft_app_init(int argc, char **argv)
{
	t_app	app;

	app = (t_app) {
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
		ft_quit(&app);
	ft_parser(argv[1], &app);
	if (!app.mlx || !app.map.init)
		ft_init_error(&app, "mlx initialisation error.");
	app.img.data = mlx_xpm_file_to_image(app.mlx,
		 "/Users/tbrouill/Desktop/RWBY-7.XPM", &app.img.width, &app.img.height);
	app.win = mlx_new_window(app.mlx, app.win_width, app.win_height, "RWBY");
	return (app);
}
