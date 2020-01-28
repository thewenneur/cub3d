/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:54:05 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 04:57:53 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_get_win_size(t_app *app, const char *str)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	app->win_width = ft_atoi(tmp [1]);
	app->win_height = ft_atoi(tmp [2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	if (!app->win_width || !app->win_height)
		ft_init_error(app, "Couldn't parse the resolution (R) parameter");
}

void		ft_get_floor_color(t_app *app, const char *str)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(str + 2, ',');
	while (tmp[++i])
	{
		app->map.f_color[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	if (app->map.f_color[0] == -1 || app->map.f_color[1] == -1
	|| app->map.f_color[2] == -1 || tmp[i])
		ft_init_error(app, "Couldn't parse the floor color (F) parameter");
	free(tmp);
}

void		ft_get_roof_color(t_app *app, const char *str)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(str + 2, ',');
	while (tmp[++i] && i < 3)
	{
		app->map.c_color[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	if (app->map.c_color[0] == -1 || app->map.c_color[1] == -1
		|| app->map.c_color[2] == -1 || tmp[i])
		ft_init_error(app, "Couldn't parse the roof color (C) parameter");
	free(tmp);
}

static void	ft_parse_line_from_file(t_app *app, char **str, int map_fd)
{
	if (**str == 'R' && *((*str) + 1) == ' ')
		ft_get_win_size(app, *str);
	else if (**str == 'N' && *((*str) + 1) == 'O' && *((*str) + 2) == ' ')
		get_texture_n(app, *str);
	else if (**str == 'S' && *((*str) + 1) == 'O' && *((*str) + 2) == ' ')
		get_texture_s(app, *str);
	else if (**str == 'W' && *((*str) + 1) == 'E' && *((*str) + 2) == ' ')
		get_texture_w(app, *str);
	else if (**str == 'E' && *((*str) + 1) == 'A' && *((*str) + 2) == ' ')
		get_texture_e(app, *str);
	else if (**str == 'S' && *((*str) + 1) == ' ')
		get_texture_sprite(app, *str);
	else if (**str == 'F' && *((*str) + 1) == ' ')
		ft_get_floor_color(app, *str);
	else if (**str == 'C' && *((*str) + 1) == ' ')
		ft_get_roof_color(app, *str);
	else if (**str)
		ft_get_map_grid(app, str, map_fd);
	if (*str)
		free(*str);
}

void		ft_parse_from_file(t_app *app, int map_fd)
{
	char	*str;

	while (get_next_line(map_fd, &str) > 0)
		ft_parse_line_from_file(app, &str, map_fd);
	ft_parse_line_from_file(app, &str, map_fd);
}
