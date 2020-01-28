/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:36:24 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 05:08:19 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_frame(t_app *app)
{
	static int frame;

	ft_putstr_fd("Frame nbr\t", 1);
	ft_putnbr_fd(frame, 1);
	ft_putchar_fd('\n', 1);
	if (!frame)
	{
		mlx_put_image_to_window(app->mlx, app->win, app->img.data, 0, 0);
		mlx_string_put(app->mlx, app->win, 0, 0, 0, "Parsing ok !");
	}
	frame++;
	return (0);
}