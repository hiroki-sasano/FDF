/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 04:34:31 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/15 19:53:43 by hisasano         ###   ########.fr       */
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


