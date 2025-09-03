/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:04:45 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 02:21:03 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_cols(char *line)
{
	int	w;
	int	in_token;

	w = 0;
	in_token = 0;
	while (*line)
	{
		if (*line != ' ' && *line != '\n' && !in_token)
		{
			in_token = 1;
			w++;
		}
		else if (*line == ' ' || *line == '\n')
		{
			in_token = 0;
		}
		line++;
	}
	return (w);
}
