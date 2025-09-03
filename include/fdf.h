/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:50:17 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 15:16:09 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef M_TAU
#  define M_TAU 6.28318530717958647692
# endif

# include "draw_map.h"
# include "fdf_keys.h"
# include "get_next_line.h"
# include "helper.h"
# include "lord_map.h"
# include "mlx.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	x_proj;
	double	y_proj;
	int		color;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		z_max;
	t_point	**points;
}			t_map;

typedef struct s_view
{
	double	zoom;
	double	ang_x;
	double	ang_y;
	double	ang_z;
	double	z_scale;
	int		off_x;
	int		off_y;
}			t_view;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_view	view;
}			t_app;

#endif
