/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:55:57 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 16:47:55 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		fdf_atoi(const char *str, int *out);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
long my_strtol_hex(const char *nptr, char **endptr);

#endif