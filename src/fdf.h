/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:50:17 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/21 21:31:46 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

//tau = 2π

#include "lord_map.h"
#include "bresenham.h"
#include "get_next_line.h"
#include "helper.h"

typedef struct s_point {
    double x;       // 元のX座標（列番号）
    double y;       // 元のY座標（行番号）
    double z;       // 高さ（mapの値）
    double x_proj;  // 投影後のX座標
    double y_proj;  // 投影後のY座標
} t_point;

typedef struct s_map {
    int     width;
    int     height;
    t_point **points;   // ← int **map の代わりに t_point **にしておく
} t_map;

/* app.h : MLXや投影パラメータも一緒に持つとさらに楽 */
typedef struct s_view {
    double zoom;       // ズーム倍率
    double ang_iso;    // 等角投影の角度（例：30°）
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

/*

typedef struct s_map {
    int   **map;    
    int     width;
    int     height;
} t_map;

// app.h : MLXや投影パラメータも一緒に持つとさらに楽 
typedef struct s_view {
    double zoom;       // ズーム
    double ang_iso;    // 等角の角度（例：30°）
    double z_scale;    // 高さ倍率
    int    off_x;      // 画面オフセット
    int    off_y;
} t_view;

typedef struct s_app {
    void  *mlx;     //mlsに渡すポインタ
    void  *win;     //window
    t_map  map;   // ←ここに地形データ
    t_view view;  // ←描画パラメータ
} t_app;


#endif

*/