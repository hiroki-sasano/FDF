/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:42:58 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 16:43:41 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <limits.h>

long my_strtol_hex(const char *nptr, char **endptr)
{
    const char *s = nptr;
    long result = 0;
    int neg = 0;

    // 空白スキップ
    while (isspace((unsigned char)*s))
        s++;

    // 符号
    if (*s == '+' || *s == '-') {
        if (*s == '-')
            neg = 1;
        s++;
    }

    // 0x / 0X をスキップ
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        s += 2;

    const char *start = s;
    while (*s) {
        int digit;

        if (isdigit((unsigned char)*s))
            digit = *s - '0';
        else if (*s >= 'a' && *s <= 'f')
            digit = *s - 'a' + 10;
        else if (*s >= 'A' && *s <= 'F')
            digit = *s - 'A' + 10;
        else
            break;

        result = result * 16 + digit;
        s++;
    }

    if (endptr)
        *endptr = (char *)(s != start ? s : nptr);

    return neg ? -result : result;
}
