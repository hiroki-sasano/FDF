/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:23:13 by hisasano          #+#    #+#             */
/*   Updated: 2025/08/28 19:23:25 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mouse_hook(int button, int x, int y, void *param)
{
    t_app *app = (t_app *)param;
    (void)x;
    (void)y;

    if (button == MOUSE_SCROLL_UP)      // ホイール ↑
        app->view.zoom *= 1.1;          // ズームイン
    else if (button == MOUSE_SCROLL_DOWN) // ホイール ↓
        app->view.zoom /= 1.1;          // ズームアウト

    return (0);
}
