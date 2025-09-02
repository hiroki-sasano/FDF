/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 04:34:31 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 20:26:34 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

static void	offset_z_scale(t_view *view, t_map *map)
{
	int	xy_max;

	if (!map || map->z_max == 0)
	{
		view->z_scale = 1.0;
		return ;
	}
	xy_max = fmax((double)map->width, (double)map->height);
	if (xy_max < (map->z_max / 2))
		view->z_scale = (double)xy_max / (double)map->z_max;
	else
		view->z_scale = 1.0;
}

void	reset_view(t_view *view, int win_w, int win_h, t_map *map)
{
	double	zoom_x;
	double	zoom_y;

	zoom_x = (double)win_w / map->width;
	zoom_y = (double)win_h / map->height;
	view->zoom = fmin(zoom_x, zoom_y) * 0.4;
	view->ang_x = M_TAU / 24;
	view->ang_y = M_TAU / 60;
	view->ang_z = 0;
	view->z_scale = 1;
	view->off_x = win_w / 2 - (int)(map->width * view->zoom * 0.4);
	view->off_y = win_h / 2 - (int)(map->height * view->zoom * 0.25);
}

static void	exit_error(const char *msg, t_app *app)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (app)
		map_free(&app->map);
	exit(1);
}

static void	init_mlx(t_app *app, int win_w, int win_h)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		exit_error("mlx_init failed\n", app);
	app->win = mlx_new_window(app->mlx, win_w, win_h, "FDF");
	if (!app->win)
		exit_error("mlx_new_window failed\n", app);
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		return (1);
	if (!load_map(argv[1], &app.map))
		exit_error("map load failed\n", &app);
	init_mlx(&app, 1200, 800);
	reset_view(&app.view, 1200, 800, &app.map);
	offset_z_scale(&app.view, &app.map);
	draw_map(&app);
	setup_hooks(&app);
	mlx_loop(app.mlx);
	map_free(&app.map);
	return (0);
}

// # define M_PI 3.14159265358979323846
