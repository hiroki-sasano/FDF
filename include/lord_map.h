/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lord_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:21:51 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/06 17:28:31 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LORD_MAP_H
# define LORD_MAP_H

typedef struct s_map	t_map;

void					map_free(t_map *m);
int						load_map(const char *path, t_map *out);
int						count_cols(char *line);
void					free_split(char **nums);
int						measure_map(int fd, t_map *out);
int						parse_row(char **nums, t_point *row, int y, t_map *map);
void					reset_view(t_view *v, int win_w, int win_h, t_map *m);

#endif