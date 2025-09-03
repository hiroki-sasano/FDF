/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:42:34 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 21:06:49 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_H
# define DRAW_MAP_H

typedef struct s_bres
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
}						t_bres;

typedef struct s_app	t_app;
typedef struct s_point	t_point;
typedef struct s_view	t_view;
typedef struct s_map	t_map;

void					bresenham_draw(t_app *app, t_point *p1, t_point *p2);
void					draw_map(t_app *app);
void					project_point(t_point *p, t_view *v);

int						close_window(void *param);
int						key_hook(int keycode, void *param);

void					reset_view(t_view *view, int win_w, int win_h,
							t_map *map);

void					setup_hooks(t_app *app);

#endif