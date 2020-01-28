/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 04:47:39 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/28 04:47:39 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_error(t_app *app, const char *str)
{
	app->map.init = 0;
	app->error = ft_strdup(str);
	ft_quit(app);
}
