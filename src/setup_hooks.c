/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:01:40 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 23:04:50 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_hooks(t_app *app)
{
	mlx_mouse_hook(app->win, mouse_hook, app);
	mlx_key_hook(app->win, key_hook, app);
	mlx_hook(app->win, 17, 1L << 17, close_window, app);
}

// マウスホイール：ズームイン／アウト
// キーボード操作（ESCで終了など）
// ウィンドウの×ボタン（DestroyNotify)
