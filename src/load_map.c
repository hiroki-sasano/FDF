/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:30:00 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/21 17:54:33 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

void	map_free(t_map *m)
{
	int	r;

	if (!m || !m->points)
		return ;
	r = 0;
	while (r < m->height)
	{
		free(m->points[r]);
		r++;
	}
	free(m->points);
	m->points = NULL;
	m->width = 0;
	m->height = 0;
}

static int	measure_map(int fd, t_map *out)
{
	char	*line;
	int		h;
	int		w;
	int		wmax;

	out->width = 0;
	out->height = 0;
	h = 0;
	wmax = 0;
	line = get_next_line(fd);
	while (line)
	{
		w = count_cols(line);
		if (w > wmax)
			wmax = w;
		h++;
		free(line);
		line = get_next_line(fd);
	}
	if (h == 0 || wmax == 0)
		return (0);
	out->height = h;
	out->width = wmax;
	return (1);
}

static int	parse_row(char **nums, t_point *row, int y, int width)
{
	int		x;
	int		val;

	x = 0;
	while (x < width)
	{
		if (!nums[x])               // 列不足
			return (0);
		if (!fdf_atoi(nums[x], &val)) // 変換失敗
			return (0);
		row[x].x = x;
		row[x].y = y;
		row[x].z = val;
		row[x].x_proj = 0;
		row[x].y_proj = 0;
		x++;
	}
	if (nums[x])                    // 列過剰
		return (0);
	return (1);
}

static int	load_rows(int fd, t_map *map)
{
	char	*line;
	char	**nums;
	int		y;

	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		return (0);
	y = 0;
	while ((line = get_next_line(fd)))
	{
		nums = ft_split(line, ' ');
		map->points[y] = malloc(sizeof(t_point) * map->width);
		if (!map->points[y] || !nums)
			return (0);
		parse_row(nums, map->points[y], y, map->width);
		free_split(nums);
		free(line);
		y++;
	}
	return (1);
}

int	load_map(const char *path, t_map *out)
{
	int	fd;

	out->points = NULL;
	out->width = 0;
	out->height = 0;

	// 1回目：マップサイズを測定
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!measure_map(fd, out))
		return (close(fd), 0);
	close(fd);

	// 2回目：points にデータをロード
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!load_rows(fd, out))
		return (close(fd), 0);
	close(fd);

	return (1);
}

