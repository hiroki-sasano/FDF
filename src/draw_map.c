/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:31:28 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/28 15:31:49 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <unistd.h>   // write
#include <stdlib.h>   // free

/* 点を等角投影する */
static void project_point(t_point *p, t_view *v)
{
    double x = p->x;
    double y = p->y;
    double z = p->z * v->z_scale;

    p->x_proj = (x - y) * cos(v->ang_iso) * v->zoom + v->off_x;
    p->y_proj = (x + y) * sin(v->ang_iso) * v->zoom - z + v->off_y;
}

/* map全体を描画 */
void draw_map(t_app *app)
{
    int x, y;

    mlx_clear_window(app->mlx, app->win);
    for (y = 0; y < app->map.height; y++)
    {
        for (x = 0; x < app->map.width; x++)
        {
            t_point *p = &app->map.points[y][x];
            project_point(p, &app->view);
            // 右隣と結ぶ
            if (x + 1 < app->map.width)
                bresenham_draw(app, p, &app->map.points[y][x+1]);
            // 下隣と結ぶ
            if (y + 1 < app->map.height)
                bresenham_draw(app, p, &app->map.points[y+1][x]);
        }
    }
}
