/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:23:18 by hisasano          #+#    #+#             */
/*   Updated: 2025/06/09 17:57:14 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

char	*get_next_line(int fd);
size_t	my_strlen(const char *s);
void	*my_memcpy(void *dst, const void *src, size_t n);
char	*my_strjoin(char const *s1, char *s2);
char	*my_strchr(const char *s, int c);
char	*my_strdup(const char *s);

#endif