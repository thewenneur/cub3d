/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:09:48 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 00:17:38 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_quit(t_mlx *mlx)
{
	if (mlx->mlx && mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->error)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd(mlx->error, 1);
		free(mlx->error);
	}
	else if (errno)
		perror("Error\n");
	exit(errno);
}
