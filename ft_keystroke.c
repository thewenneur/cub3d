/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keystroke.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:40:46 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/26 20:32:31 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_keystroke(int keycode, t_app *app)
{
	(void)app;
	printf("Keycode\t:\t%d\n", keycode);
	if (keycode == 53)
		ft_quit(app);
	return (0);
}