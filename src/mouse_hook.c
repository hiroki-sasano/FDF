/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:23:13 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/02 23:06:49 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		app->view.zoom *= 1.1;
	else if (button == MOUSE_SCROLL_DOWN)
		app->view.zoom /= 1.1;
	return (0);
}
