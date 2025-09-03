/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:41:29 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 21:06:44 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_app *app, int x, int y, int color)
{
	mlx_pixel_put(app->mlx, app->win, x, y, color);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	step_line(t_bres *b)
{
	int	e2;

	e2 = 2 * b->err;
	if (e2 > -b->dy)
	{
		b->err -= b->dy;
		b->x1 += b->sx;
	}
	if (e2 < b->dx)
	{
		b->err += b->dx;
		b->y1 += b->sy;
	}
}

void	bresenham_draw(t_app *app, t_point *p1, t_point *p2)
{
	t_bres	b;

	b.x1 = (int)p1->x_proj;
	b.y1 = (int)p1->y_proj;
	b.x2 = (int)p2->x_proj;
	b.y2 = (int)p2->y_proj;
	b.dx = ft_abs(b.x2 - b.x1);
	b.dy = ft_abs(b.y2 - b.y1);
	if (b.x1 < b.x2)
		b.sx = 1;
	else
		b.sx = -1;
	if (b.y1 < b.y2)
		b.sy = 1;
	else
		b.sy = -1;
	b.err = b.dx - b.dy;
	while (1)
	{
		put_pixel(app, b.x1, b.y1, p1->color);
		if (b.x1 == b.x2 && b.y1 == b.y2)
			break ;
		step_line(&b);
	}
}
