/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lord_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:21:51 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/21 17:45:58 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LORD_MAP_H
# define LORD_MAP_H

# include "fdf.h"

void	map_free(t_map *m);
int		load_map(const char *path, t_map *out);

#endif