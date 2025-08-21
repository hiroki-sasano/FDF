/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_to_ints.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 22:04:41 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/18 16:33:29 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	free_split(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

/* row/tokens をまとめて解放して NULL を返す */
static int	*fail_cleanup(int *row, char **tokens)
{
	if (row)
		free(row);
	free_split(tokens);
	return (NULL);
}

int	*parse_line_to_ints(char *line, int width)
{
	char	**tokens;
	int		*row;
	int		i;
	int		val;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	row = (int *)malloc(sizeof(int) * width);
	if (!row)
		return (fail_cleanup(NULL, tokens));
	i = 0;
	while (i < width)
	{
		if (!tokens[i])                      /* 列不足 */
			return (fail_cleanup(row, tokens));
		if (!fdf_atoi(tokens[i], &val))      /* 不正数/オーバーフロー */
			return (fail_cleanup(row, tokens));
		row[i] = val;
		i++;
	}
	if (tokens[i])                           /* 余計なトークン（列過剰） */
		return (fail_cleanup(row, tokens));
	free_split(tokens);
	return (row);
}

