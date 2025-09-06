/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:31:28 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/06 17:54:05 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_right(t_app *app, t_point *p, int y, int x)
{
	t_point	*pr;

	if (x + 1 < app->map.width)
	{
		pr = &app->map.points[y][x + 1];
		project_point(pr, &app->view);
		bresenham_draw(app, p, pr);
	}
}

static void	draw_down(t_app *app, t_point *p, int y, int x)
{
	t_point	*pd;

	if (y + 1 < app->map.height)
	{
		pd = &app->map.points[y + 1][x];
		project_point(pd, &app->view);
		bresenham_draw(app, p, pd);
	}
}

void	draw_map(t_app *app)
{
	t_point	*p;
	int		x;
	int		y;

	app->img.img = mlx_new_image(app->mlx, 800, 600);
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bpp,
			&app->img.line_len, &app->img.endian);
	y = 0;
	while (y < app->map.height)
	{
		x = 0;
		while (x < app->map.width)
		{
			p = &app->map.points[y][x];
			project_point(p, &app->view);
			draw_right(app, p, y, x);
			draw_down(app, p, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
}
