/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:50:17 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/15 20:24:35 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_map {
    int   **map;     // 高さマップ [height][width]
    int     width;
    int     height;
} t_map;

/* app.h : MLXや投影パラメータも一緒に持つとさらに楽 */
typedef struct s_view {
    double zoom;       // ズーム
    double ang_iso;    // 等角の角度（例：30°）
    double z_scale;    // 高さ倍率
    int    off_x;      // 画面オフセット
    int    off_y;
} t_view;

typedef struct s_app {
    void  *mlx;
    void  *win;
    t_map  map;   // ←ここに地形データ
    t_view view;  // ←描画パラメータ
} t_app;

/* 読み込み／解放のインタフェース */
int  map_load_from_file(const char *path, t_map *out); 
void map_free(t_map *m);

#endif
