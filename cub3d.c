/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:24:20 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 05:50:26 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_app	app;

	app = ft_app_init(argc, argv);
	mlx_key_hook(app.win, &ft_keystroke, &app);
	mlx_hook(app.win, 17, (1L << 17), &ft_quit, &app);
	mlx_loop_hook(app.mlx, &ft_frame, &app);
	mlx_loop(app.mlx);
	return (0);
}
