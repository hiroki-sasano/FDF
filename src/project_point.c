/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:18:38 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/01 19:20:00 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	rotate_x(double *y, double *z, double angle)
{
	double	old_y;
	double	old_z;

	old_y = *y;
	old_z = *z;
	*y = old_y * cos(angle) - old_z * sin(angle);
	*z = old_y * sin(angle) + old_z * cos(angle);
}

static void	rotate_y(double *x, double *z, double angle)
{
	double	old_x;
	double	old_z;

	old_x = *x;
	old_z = *z;
	*x = old_x * cos(angle) + old_z * sin(angle);
	*z = -old_x * sin(angle) + old_z * cos(angle);
}

static void	rotate_z(double *x, double *y, double angle)
{
	double	old_x;
	double	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(angle) - old_y * sin(angle);
	*y = old_x * sin(angle) + old_y * cos(angle);
}

void	project_point(t_point *p, t_view *v)
{
	double	x;
	double	y;
	double	z;

	x = p->x;
	y = p->y;
	z = p->z * v->z_scale;
	rotate_x(&y, &z, v->ang_x);
	rotate_y(&x, &z, v->ang_y);
	rotate_z(&x, &y, v->ang_z);
	p->x_proj = x * v->zoom + v->off_x;
	p->y_proj = y * v->zoom + v->off_y;
}
