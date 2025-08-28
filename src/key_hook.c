/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:07:08 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/28 20:42:30 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h> // exit()

int	key_hook(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == KEY_ESC)
	{
		map_free(&app->map);
		mlx_destroy_window(app->mlx, app->win);
		exit(0);
	}
	else if (keycode == KEY_UP)
		app->view.off_y -= 10;
	else if (keycode == KEY_DOWN)
		app->view.off_y += 10;
	else if (keycode == KEY_LEFT)
		app->view.off_x -= 10;
	else if (keycode == KEY_RIGHT)
		app->view.off_x += 10;
	else if (keycode == KEY_Q)
		app->view.ang_iso -= 0.1;
	else if (keycode == KEY_E)
		app->view.ang_iso += 0.1;
	else if (keycode == KEY_UP)
		app->view.z_scale += 0.1;
	else if (keycode == KEY_DOWN)
		app->view.z_scale -= 0.1;
	else if (keycode == KEY_PLUS)
		app->view.zoom *= 1.1;
	else if (keycode == KEY_MINUS)
		app->view.zoom /= 1.1;
	return (0);
}

int	close_window(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	map_free(&app->map);
	mlx_destroy_window(app->mlx, app->win);
	exit(0);
	return (0);
}
