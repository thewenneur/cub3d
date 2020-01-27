/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:06:48 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 02:11:52 by tbrouill         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"

typedef struct	s_img {
	int		width;
	int		height;
	void	*data;
}				t_img;

typedef struct	s_map {
	int		init;
	int		f_color[3];
	int		c_color[3];
	t_img	n_texture;
	t_img	s_texture;
	t_img	w_texture;
	t_img	e_texture;
	t_img	sprite_texture;
}				t_map;

typedef struct	s_mlx{
	char	*error;
	char	*save_path;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;
	void	*mlx;
	void	*win;
}				t_mlx;

char	*ft_get_save_path(int argc, char **argv);
int		ft_quit(t_mlx *mlx);
int		ft_frame(t_mlx *mlx);
int		ft_keystroke(int keycode, t_mlx *mlx);
int		ft_parser(char *filepath, t_mlx *mlx);
t_mlx	ft_mlx_init(int argc, char **argv);
void	ft_parse_from_file(t_mlx *mlx, int map_fd);
void 	get_texture_n(t_mlx *mlx, char *str);
void 	get_texture_s(t_mlx *mlx, char *str);
void 	get_texture_w(t_mlx *mlx, char *str);
void 	get_texture_e(t_mlx *mlx, char *str);
void 	get_texture_sprite(t_mlx *mlx, char *str);
void 	ft_get_win_size(t_mlx *mlx, const char *str);
void	ft_get_floor_color(t_mlx *mlx, const char *str);
void	ft_get_roof_color(t_mlx *mlx, const char *str);

#endif
