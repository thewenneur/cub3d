/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:11:45 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/27 05:49:16 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_malloc_string_tab(t_mlx *mlx, int *j)
{
	if (!(mlx->map.map_grid = malloc(sizeof(char *) * (++(*j)))))
	{
		mlx->error = ft_strdup("Memory allocation error.");
		mlx->map.init = 0;
		ft_quit(mlx);
	}
}

void ft_add_line_to_map_grid(t_mlx *mlx, char **str, int *j)
{
	char	**ptr;
	int		i;

	i = -1;
	ptr = mlx->map.map_grid;
	ft_malloc_string_tab(mlx, j);
	while (++i < *j)
		mlx->map.map_grid[i] = ptr[i];
	mlx->map.map_grid[*j] = *str;
	free(ptr);
}

void	ft_get_map_grid_from_file(t_mlx *mlx, char **str, const int map_fd)
{
	int		i;
	int		j;
	char	*ptr;

	j = -1;
	ft_malloc_string_tab(mlx, &j);
	mlx->map.map_grid[j] = *str;
	while (get_next_line(map_fd, str) > 0)
	{
		i = 0;
		while ((*str)[i] && ((**str >= '0' && **str <= '2') || **str == 'N'
		|| **str == 'S' || **str == 'W' || **str == 'E'))
			i++;
		if (!(*str)[i])
			ft_add_line_to_map_grid(mlx, str, &j);
		*str = NULL;
	}
	ptr = NULL;
	ft_add_line_to_map_grid(mlx, &ptr, &j);
}

void	ft_check_map_grid_payer_start(t_mlx *mlx, unsigned int x,
													unsigned int y)
{
	if (mlx->map.map_grid[y][x] == 'N')
	{
		mlx->map.player_start.dir = 0.0;
		mlx->map.player_start.x = x;
		mlx->map.player_start.y = y;
		mlx->map.map_grid[y][x] = '0';
	}
	else if (mlx->map.map_grid[y][x] == 'S')
	{
		mlx->map.player_start.dir = 180.0;
		mlx->map.player_start.x = x;
		mlx->map.player_start.y = y;
		mlx->map.map_grid[y][x] = '0';
	}
	else if (mlx->map.map_grid[y][x] == 'E')
	{
		mlx->map.player_start.dir = 275.0;
		mlx->map.player_start.x = x;
		mlx->map.player_start.y = y;
		mlx->map.map_grid[y][x] = '0';
	}
	else if (mlx->map.map_grid[y][x] == 'W')
	{
		mlx->map.player_start.dir = 90.0;
		mlx->map.player_start.x = x;
		mlx->map.player_start.y = y;
		mlx->map.map_grid[y][x] = '0';
	}
}

void	ft_check_map_grid(t_mlx *mlx)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	x_max;
	unsigned int	y_max;

	y = -1;
	x_max = 0;
	y_max = 0;
	while (mlx->map.map_grid[y_max])
		y_max++;
	while (++y < y_max)
	{
		x = -1;
		if (ft_strlen(mlx->map.map_grid[y]) > x_max)
			x_max = ft_strlen(mlx->map.map_grid[y]);
		while (++x < x_max)
			ft_check_map_grid_payer_start(mlx, x, y);
	}

}

void	ft_get_map_grid(t_mlx *mlx, char **str, int map_fd)
{
	int		i;

	i = 0;
	while ((*str)[i] && ((**str >= '0' && **str <= '2') || **str == 'N'
	|| **str == 'S' || **str == 'W' || **str == 'E'))
		i++;
	if (!(*str)[i])
	{
		ft_get_map_grid_from_file(mlx, str, map_fd);
		ft_check_map_grid(mlx);
	}
}
