/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:01:40 by hisasano          #+#    #+#             */
/*   Updated: 2025/09/03 19:19:27 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_hooks(t_app *app)
{
	mlx_key_hook(app->win, key_hook, app);
	mlx_hook(app->win, 17, 1L << 17, close_window, app);
}
