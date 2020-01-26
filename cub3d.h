/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:06:48 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/26 21:50:46 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H
# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include "libft/libft.h"

typedef struct	s_img {
	void	*data;
	int		width;
	int		height;
}				t_img;

typedef struct	s_mlx{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;

int		ft_quit(t_mlx *mlx);
int		ft_frame(t_mlx *mlx);
int		ft_keystroke(int keycode, t_mlx *mlx);

#endif
