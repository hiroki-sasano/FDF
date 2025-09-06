/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 04:34:31 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/06 17:50:20 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	offset_z_scale(t_view *view, t_map *map)
{
	double	xy_max;

	if (!map || map->z_max == 0)
	{
		view->z_scale = 1.0;
		return ;
	}
	xy_max = fmax((double)map->width, (double)map->height);
	view->z_scale = fmin(1.0, xy_max / (double)map->z_max);
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

static void	init_image(t_app *app, int win_w, int win_h)
{
	app->img.img = mlx_new_image(app->mlx, win_w, win_h);
	if (!app->img.img)
		exit_error("mlx_new_image failed\n", app);
	app->img.addr = mlx_get_data_addr(app->img.img,
			&app->img.bpp, &app->img.line_len, &app->img.endian);
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		return (1);
	if (!load_map(argv[1], &app.map))
		exit_error("map load failed\n", &app);
	init_mlx(&app, 800, 600);
	init_image(&app, 800, 600);
	reset_view(&app.view, 800, 600, &app.map);
	offset_z_scale(&app.view, &app.map);
	draw_map(&app);
	setup_hooks(&app);
	mlx_loop(app.mlx);
	map_free(&app.map);
	return (0);
}

// # define M_PI 3.14159265358979323846
