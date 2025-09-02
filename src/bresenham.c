/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:41:29 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 16:41:25 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>  // abs()

static void	put_pixel(t_app *app, int x, int y, int color)
{
    mlx_pixel_put(app->mlx, app->win, x, y, color);
}

void bresenham_draw(t_app *app, t_point *p1, t_point *p2)
{
    int x1 = (int)p1->x_proj;
    int y1 = (int)p1->y_proj;
    int x2 = (int)p2->x_proj;
    int y2 = (int)p2->y_proj;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        put_pixel(app, x1, y1, p1->color);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
