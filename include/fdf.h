/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:50:17 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 18:58:24 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#ifndef M_TAU
# define M_TAU 6.28318530717958647692
#endif

#include "draw_map.h"
#include "fdf_keys.h"
#include "lord_map.h"
#include "get_next_line.h"
#include "helper.h"
#include "mlx.h"

typedef struct s_point {
    double x;       // 元のX座標（列番号）
    double y;       // 元のY座標（行番号）
    double z;       // 高さ（mapの値）
    double x_proj;  // 投影後のX座標
    double y_proj;  // 投影後のY座標
    int color;
} t_point;

typedef struct s_map {
    int     width;
    int     height;
    int     z_max;     
    t_point **points;
} t_map;

typedef struct s_view {
    double zoom;       // ズーム倍率
    double ang_x;
    double ang_y;
    double ang_z;
    double z_scale;    // 高さ倍率
    int    off_x;      // X方向オフセット
    int    off_y;      // Y方向オフセット
} t_view;

typedef struct s_app {
    void  *mlx;     // MLXコンテキスト
    void  *win;     // ウィンドウ
    t_map  map;     // 地形データ
    t_view view;    // 投影・描画パラメータ
} t_app;

#endif
