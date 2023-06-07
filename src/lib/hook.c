/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:57:45 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 13:04:24 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "internal.h"
#include <X11/X.h>
#include <mlx.h>
#include <stddef.h>

void	on_keydown(t_canvas *cv, int (*f)(), void *param)
{
	mlx_hook(cv->p_impl->window, KeyPress, KeyPressMask, f, param);
}

void	on_destroy(t_canvas *cv, int (*f)(), void *param)
{
	mlx_hook(cv->p_impl->window, DestroyNotify, StructureNotifyMask, f, param);
}

void	clear_event_handler(t_canvas *cv)
{
	on_keydown(cv, NULL, NULL);
	on_destroy(cv, NULL, NULL);
	mlx_mouse_hook(cv->p_impl->window, NULL, NULL);
	mlx_expose_hook(cv->p_impl->window, NULL, NULL);
	mlx_loop_hook(cv->p_impl->mlx, NULL, NULL);
}
