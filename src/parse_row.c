/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:38:39 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 20:18:30 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	update_z_max(t_map *map, int z)
{
	int	abs_z;

	if (z < 0)
		abs_z = -z;
	else
		abs_z = z;
	if (abs_z > map->z_max)
		map->z_max = abs_z;
}

static void	set_point(t_point *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
	p->x_proj = 0;
	p->y_proj = 0;
}

static char	*split_comma(char *s)
{
	char	*comma;

	comma = ft_strchr(s, ',');
	if (comma)
	{
		*comma = '\0';
		comma++;
	}
	return (comma);
}

static int	get_color(char *comma)
{
	if (comma)
		return ((int)my_strtol_hex(comma, NULL));
	return (0xFFFFFF);
}

int	parse_row(char **nums, t_point *row, int y, int width, t_map *map)
{
	int		x;
	char	*comma;
	int		val;

	x = 0;
	while (x < width)
	{
		if (!nums[x])
			return (0);
		comma = split_comma(nums[x]);
		if (!fdf_atoi(nums[x], &val))
			return (0);
		set_point(&row[x], x, y, val);
		update_z_max(map, val);
		row[x].color = get_color(comma);
		x++;
	}
	return (nums[x] == NULL);
}
