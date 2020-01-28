/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:06:48 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 05:50:26 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H
# include "/usr/local/include/mlx.h"
# include "X11/X.h"
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

typedef struct	s_player {
	unsigned int	x;
	unsigned int	y;
	double			dir;
}				t_player;

typedef struct	s_map {
	int			init;
	int			f_color[3];
	int			c_color[3];
	char		**map_grid;
	t_img		n_texture;
	t_img		s_texture;
	t_img		w_texture;
	t_img		e_texture;
	t_img		sprite_texture;
	t_player	player_start;
}				t_map;

typedef struct	s_app{
	char		*error;
	char		*save_path;
	int			win_height;
	int			win_width;
	t_img		img;
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
}				t_app;

char	*ft_get_save_path(int argc, char **argv);
int		ft_quit(t_app *app);
int		ft_frame(t_app *app);
int		ft_keystroke(int keycode, t_app *app);
int		ft_parser(char *filepath, t_app *app);
t_app	ft_app_init(int argc, char **argv);
void	ft_check_map_grid(t_app *app);
void	ft_init_error(t_app *app, const char *str);
void	ft_parse_from_file(t_app *app, int map_fd);
void 	ft_get_win_size(t_app *app, const char *str);
void	ft_get_floor_color(t_app *app, const char *str);
void	ft_get_roof_color(t_app *app, const char *str);
void	ft_get_map_grid(t_app *app, char **str, int map_fd);
void 	get_texture_n(t_app *app, char *str);
void 	get_texture_s(t_app *app, char *str);
void 	get_texture_w(t_app *app, char *str);
void 	get_texture_e(t_app *app, char *str);
void 	get_texture_sprite(t_app *app, char *str);
#endif
