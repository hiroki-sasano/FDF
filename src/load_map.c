/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:30:00 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/15 20:25:17 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

int map_load_from_file(const char *path, t_map *out)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1) return 0;

    // 1周目：height/width 測定
    int height = 0, width = 0;
    char *line;
    while ((line = get_next_line(fd))) 
	{
        int w = count_cols(line); // 空白区切りの個数を数える
        if (w > width) 
			width = w;
        height++;
        free(line);
    }
    if (height == 0 || width == 0) 
	{
		close(fd); 
		return 0;
	}
    
    // メモリ確保
    int **map = malloc(sizeof(int*) * height);
    if (!map) 
	{
		close(fd);
		return 0;
	}

    // 2周目：実データ読み込み
    for (int r = 0; r < h; r++) {
        line = get_next_line(fd);
        if (!line) { /* 失敗処理 */ }
        z[r] = parse_line_to_ints(line, wmax); // 列不足の扱いは方針次第
        free(line);
        if (!z[r]) { /* 失敗処理（確保済み行をfree）*/ }
    }
    close(fd);

    // 完成：outに集約
    out->map = map;
    out->height = height;
    out->width  = width;
    return 1;
}

void map_free(t_map *m)
{
    if (!m || !m->z) return;
    for (int r = 0; r < m->height; r++) free(m->z[r]);
    free(m->z);
    m->z = NULL;
    m->height = m->width = 0;
}

