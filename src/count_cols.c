/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:04:45 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 17:45:20 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int count_cols(char *line)
{
    int w = 0;
    int in_token = 0;

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
    return w;
}
