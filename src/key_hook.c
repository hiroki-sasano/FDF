/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:07:08 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 16:51:51 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

static void	handle_move(int keycode, t_app *app)
{
	if (keycode == KEY_UP)
		app->view.off_y -= 10;
	else if (keycode == KEY_DOWN)
		app->view.off_y += 10;
	else if (keycode == KEY_LEFT)
		app->view.off_x -= 10;
	else if (keycode == KEY_RIGHT)
		app->view.off_x += 10;
}

static void	handle_rotate(int keycode, t_app *app)
{
	if (keycode == KEY_Q)
		app->view.ang_z -= 0.1;
	else if (keycode == KEY_E)
		app->view.ang_z += 0.1;
	else if (keycode == KEY_W)
		app->view.ang_x -= 0.1;
	else if (keycode == KEY_S)
		app->view.ang_x += 0.1;
	else if (keycode == KEY_A)
		app->view.ang_y -= 0.1;
	else if (keycode == KEY_D)
		app->view.ang_y += 0.1;
}

static void	handle_scale_zoom(int keycode, t_app *app)
{
	if (keycode == KEY_U)
		app->view.z_scale += 0.1;
	else if (keycode == KEY_H)
		app->view.z_scale -= 0.1;
	else if (keycode == KEY_PLUS)
		app->view.zoom *= 1.1;
	else if (keycode == KEY_MINUS)
		app->view.zoom /= 1.1;
}

int	key_hook(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == KEY_ESC)
	{
		map_free(&app->map);
		exit(0);
	}
	handle_move(keycode, app);
	handle_rotate(keycode, app);
	handle_scale_zoom(keycode, app);
	draw_map(app);
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
