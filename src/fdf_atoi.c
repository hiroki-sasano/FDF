/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:32:09 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/18 16:32:36 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static const char	*skip_ws(const char *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	return (s);
}

static int	change_dc(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

static int	add_digit_safe(long *res, int dig)
{
	if (*res > (LONG_MAX - dig) / 10)
		return (0);
	*res = (*res * 10) + dig;
	return (1);
}

static const char	*parse_sign(const char *s, int *sign)
{
	*sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
	return (s);
}

int	fdf_atoi(const char *str, int *out)
{
	long	res;
	int		sign;
	int		dig;

	if (!str || !*str)
		return (0);
	str = skip_ws(str);
	str = parse_sign(str, &sign);
	if (chamge_dc(*str) < 0)
		return (0);
	res = 0;
	while (dig >= 0)
	{
		if (!add_digit_safe(&res, &dig))
			return (0);
		str++;
		dig = change_dc(*str);
	}
	str = skip_ws(str);
	res *= sign;
	if (*str != '\0' || res < INT_MIN || res > INT_MAX)
		return (0);
	*out = (int)res;
	return (1);
}
