/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 03:15:32 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 05:03:11 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_malloc_string_tab(t_app *app, int *size)
{
	if (!(app->map.map_grid = malloc(sizeof(char *) * (++(*size)))))
		ft_init_error(app, "Memory allocation error.");
}

void	ft_get_map_grid_from_file(t_app *app, char **str, const int map_fd)
{
	char	*tmp;
	char	*buff;

	tmp = *str;
	while (get_next_line(map_fd, str) > 0)
	{
		buff = tmp;
		tmp = ft_strjoin(tmp, "\n");
		free(buff);
		buff = tmp;
		tmp = ft_strjoin(tmp, *str);
		free(buff);
		free(*str);
	}
	app->map.map_grid = ft_split(tmp, '\n');
	free(tmp);
}

void	ft_get_map_grid(t_app *app, char **str, int map_fd)
{
	int		i;

	i = 0;
	while ((*str)[i] && ((**str >= '0' && **str <= '2') || **str == 'N'
						 || **str == 'S' || **str == 'W' || **str == 'E'))
		i++;
	if (!(*str)[i])
	{
		ft_get_map_grid_from_file(app, str, map_fd);
		ft_check_map_grid(app);
	}
}