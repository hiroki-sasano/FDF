/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 04:34:31 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/21 15:45:34 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	reset_view(t_view *view, int win_w, int win_h, t_map *map)
{
	double	zoom_x;
	double	zoom_y;

	if (!view || !map || map->width == 0 || map->height == 0)
		return ;
	zoom_x = (double)win_w / map->width;
	zoom_y = (double)win_h / map->height;
	view->zoom = fmin(zoom_x, zoom_y) * 0.8;
	view->ang_iso = M_PI / 6;
	view->z_scale = 1.0;
	view->off_x = win_w / 2;
	view->off_y = win_h / 2;
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		return (1);
	// 1) マップ読み込み
	if (!load_map(argv[1], &app.map))
	{
		write(2, "map load failed\n", 16);
		return (1);
	}
	// test_check_map(&app.map);
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, 800, 600, "FDF");
	reset_view(&app.view, 800, 600, &app.map);
	// 3) MLX 初期化→描画（略）
	// 4) 終了時に map をまとめて解放
	map_free(&app.map);
	return (0);
}

/*
typedef struct s_map {
	int   **map;
	int     width;
	int     height;
}		t_map;

//app.h : MLXや投影パラメータも一緒に持つとさらに楽
typedef struct s_view {
	double zoom;       // ズーム
	double ang_iso;    // 等角の角度（例：30°）
	double z_scale;    // 高さ倍率
	int    off_x;      // 画面オフセット
	int    off_y;
}		t_view;

typedef struct s_app {
	void  *mlx;     //mlsに渡すポインタ
	void  *win;
	t_map  map;   // ←ここに地形データ
	t_view view;  // ←描画パラメータ
}		t_app;

*/

// # define M_PI 3.14159265358979323846
