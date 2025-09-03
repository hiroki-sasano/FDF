/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:04:53 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 15:17:40 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_KEYS_H
# define FDF_KEYS_H

# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_PLUS 61
#  define KEY_MINUS 45

// 回転キー
#  define KEY_Q 113 // Z軸 左回転
#  define KEY_E 101 // Z軸 右回転
#  define KEY_W 119 // X軸 上回転
#  define KEY_S 115 // X軸 下回転
#  define KEY_A 97  // Y軸 左回転
#  define KEY_D 100 // Y軸 右回転

// 高さ強調 (U/Hキー)
#  define KEY_U 117 // 高さ強調+
#  define KEY_H 104 // 高さ強調-

#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
# endif

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_PLUS 41  // テンキー +
#  define KEY_MINUS 27 // テンキー -

// 回転キー
#  define KEY_Q 12 // Z軸 左回転
#  define KEY_E 14 // Z軸 右回転
#  define KEY_W 13 // X軸 上回転
#  define KEY_S 1  // X軸 下回転
#  define KEY_A 0  // Y軸 左回転
#  define KEY_D 2  // Y軸 右回転

// 高さ強調
#  define KEY_U 32 // U
#  define KEY_H 4  // D (注意: macOSではAと被るので別キー推奨)

#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
# endif

#endif
