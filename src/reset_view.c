/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:34:58 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/06 17:33:05 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static inline double	deg2rad(double d)
{
	return (d * M_TAU / 360.0);
}

void	reset_view(t_view *v, int win_w, int win_h, t_map *m)
{
	double	zx;
	double	zy;

	zx = (double)win_w / m->width;
	zy = (double)win_h / m->height;
	v->zoom = fmin(zx, zy) * 0.5;
	v->ang_z = deg2rad(45.0);
	v->ang_x = deg2rad(35.2643897);
	v->ang_y = 0.0;
	v->off_x = win_w / 2;
	v->off_y = win_h / 4;
}
