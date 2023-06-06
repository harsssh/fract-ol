/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:57:45 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 21:55:40 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "internal.h"
#include <X11/X.h>
#include <mlx.h>

void	handle_mouse_event(t_canvas *canvas, int (*f)(), void *param)
{
	mlx_mouse_hook(canvas->p_impl->window, f, param);
}

void	handle_key_event(t_canvas *canvas, int (*f)(), void *param)
{
	mlx_key_hook(canvas->p_impl->window, f, param);
}

void	handle_close_event(t_canvas *canvas, int (*f)(), void *param)
{
	mlx_hook(canvas->p_impl->window, DestroyNotify, StructureNotifyMask, f, param);
}

