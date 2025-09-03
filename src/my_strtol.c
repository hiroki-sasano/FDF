/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:42:58 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 15:03:54 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	is_space(unsigned char s)
{
	if (s == ' ')
		return (1);
	return (0);
}

static int	hex_char_to_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

static const char	*skip_space_and_sign(const char *s, int *neg)
{
	while (is_space((unsigned char)*s))
		s++;
	*neg = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*neg = 1;
		s++;
	}
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		s += 2;
	return (s);
}

long	my_strtol_hex(const char *nptr, char **endptr)
{
	const char	*s;
	long		result;
	int			neg;
	int			digit;

	s = skip_space_and_sign(nptr, &neg);
	result = 0;
	while (*s)
	{
		digit = hex_char_to_val(*s);
		if (digit < 0)
			break ;
		result = result * 16 + digit;
		s++;
	}
	if (endptr)
	{
		if (s != nptr)
			*endptr = (char *)s;
		else
			*endptr = (char *)nptr;
	}
	if (neg)
		return (-result);
	return (result);
}
