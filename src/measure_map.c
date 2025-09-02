/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:08:44 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 21:31:41 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>

static int	validate_line(char *line, int *expected_w)
{
	int	w;

	w = count_cols(line);
	if (w == 0)
		return (0);
	if (*expected_w == -1)
		*expected_w = w;
	else if (w != *expected_w)
		return (0);
	return (1);
}

int	measure_map(int fd, t_map *out)
{
	char	*line;
	int		h;
	int		expected_w;

	out->width = 0;
	out->height = 0;
	h = 0;
	expected_w = -1;
	line = get_next_line(fd);
	while (line)
	{
		if (!validate_line(line, &expected_w))
			return (free(line), 0);
		h++;
		free(line);
		line = get_next_line(fd);
	}
	if (h == 0)
		return (0);
	out->height = h;
	out->width = expected_w;
	return (1);
}
