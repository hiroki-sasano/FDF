/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 04:34:31 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/29 15:44:35 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <unistd.h>

void	reset_view(t_view *view, int win_w, int win_h, t_map *map)
{
	double	zoom_x;
	double	zoom_y;

	if (!view || !map || map->width == 0 || map->height == 0)
		return ;
	zoom_x = (double)win_w / map->width;
	zoom_y = (double)win_h / map->height;
	view->zoom = fmin(zoom_x, zoom_y) * 0.8;
	view->ang_iso = M_TAU / 12;
	view->z_scale = 1.0;
	view->off_x = win_w / 2;
	view->off_y = win_h / 2;
}

int main(int argc, char **argv)
{
    t_app app;

    if (argc != 2)
        return (1);
    if (!load_map(argv[1], &app.map))
    {
        write(2, "map load failed\n", 16);
        return (1);
    }
    app.mlx = mlx_init();
    app.win = mlx_new_window(app.mlx, 800, 600, "FDF");
    reset_view(&app.view, 800, 600, &app.map);

    draw_map(&app);
	setup_hooks(&app);

    mlx_loop(app.mlx);

    map_free(&app.map);
    return (0);
}

// # define M_PI 3.14159265358979323846
