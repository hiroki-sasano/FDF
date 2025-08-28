/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:01:40 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/28 19:33:05 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void setup_hooks(t_app *app)
{
    // マウスホイール：ズームイン／アウト
    mlx_mouse_hook(app->win, mouse_hook, app);

    // キーボード操作（ESCで終了など）
    mlx_key_hook(app->win, key_hook, app);

    // ウィンドウの×ボタン（DestroyNotify）
    mlx_hook(app->win, 17, 1L<<17, close_window, app);
}
