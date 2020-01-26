/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:36:24 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 00:54:14 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_frame(t_mlx *mlx)
{
	static int frame = 0;

	(void)mlx;
	ft_putstr_fd("Frame nbr\t", 1);
	ft_putnbr_fd(frame, 1);
	ft_putchar_fd('\n', 1);
	if (!frame)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.data, 0, 0);
		mlx_string_put(mlx->mlx, mlx->win, 0, 0, 0, "Parsing ok !");
	}
	frame++;
	return (0);
}