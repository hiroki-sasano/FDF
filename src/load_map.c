/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:30:00 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 21:59:11 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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
		parse_row(nums, map->points[y], y, map->width, map);
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
	out->z_max = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "open failed\n", 12);
		return (0);
	}
	if (!measure_map(fd, out))
		return (close(fd), 0);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "second open failed\n", 19);
		return (0);
	}
	if (!load_rows(fd, out))
		return (close(fd), 0);
	close(fd);
	return (1);
}
