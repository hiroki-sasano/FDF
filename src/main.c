/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 04:34:31 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/13 21:00:36 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>          
#include <stdlib.h>     
#include <unistd.h>     
#include <string.h>     
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s1);
	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void make_map(int fd, int **z_map)
{
    char *line;
    int num = 0;
    

    while ((line = get_next_line(fd)) != NULL)
    {
        z_map[num] = ft_strdup(line);
        free(line);
        num++;
    }
}

int main(int argc, char **argv)
{
    int **z_map;

    if (argc != 2)
        return (0);

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (0);
    }
    make_map(fd, z_map);
    close(fd);

    return 0;
}


int main(int argc, char **argv)
{

	int **z_map;

	z_map = NULL;

    if (argc != 2) {
        write(2, "Usage: ./fdf <map.fdf>\n", 23);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) 
	{
		perror("open");
		return 1;
	}

    // 1周目：サイズ測定
    int height = 0, width = 0;
    if (measure_map(fd, &height, &width) != 0 || height == 0 || width == 0)
	{
        close(fd);
        write(2, "Invalid/empty map\n", 18);
        return 1;
    }
    // lseek でファイル先頭へ戻す
    if (lseek(fd, 0, SEEK_SET) == (off_t)-1) { perror("lseek"); close(fd); return 1; }

    // 2周目：読み込み
    int **z_map = NULL;
    if (load_map(fd, &z_map, height, width) != 0) {
        close(fd);
        write(2, "Parse error\n", 12);
        return 1;
    }
    close(fd);

    // ここまでで z_map[0..height-1][0..width-1] が完成
    // --- 以降：投影→描画（MiniLibX）へつなぐ ---

	int r;

	r = 0;
    // 後始末（本番はウィンドウ終了時に）
    while(r < height) 
	{
		free(z_map[r]);
		r++;
	}
    free(z_map);

    return 0;
}
