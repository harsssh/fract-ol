/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:00:40 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 00:40:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"
#include "lib/keycode.h"
#include "lib/mousecode.h"
#include <stdlib.h>

static void	shift(int key, t_context *ctx)
{
	t_complex	*z;
	double		amount;

	z = &ctx->range.corner;
	amount = ctx->range.length / 16;
	if (key == KEY_RIGHT)
		z->re += amount;
	else if (key == KEY_LEFT)
		z->re -= amount;
	else if (key == KEY_UP)
		z->im -= amount;
	else if (key == KEY_DOWN)
		z->im += amount;
}

static int	is_arrow(int key)
{
	return (key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP
		|| key == KEY_DOWN);
}

int	terminate(t_context *ctx)
{
	clear_event_handler(ctx->canvas);
	free_canvas(ctx->canvas);
	exit(0);
}

int	key_handler(int key, t_context *ctx)
{
	if (key == KEY_ESCAPE)
		terminate(ctx);
	else if (is_arrow(key))
	{
		shift(key, ctx);
		redraw(*ctx);
	}
	return (0);
}

int	mouse_handler(int button, int x, int y, t_context *ctx)
{
	double		scale;
	t_complex	center;

	if (button == MOUSE_SCROLL_UP)
		scale = 1 / SCALE_FACTOR;
	else if (button == MOUSE_SCROLL_DOWN)
		scale = SCALE_FACTOR;
	else
		return (0);
	y = ctx->canvas->height - y;
	convert_to_complex(*ctx, &center, x, y);
	ctx->range.length *= scale;
	complex_scale(&ctx->range.corner, center, scale);
	redraw(*ctx);
	return (0);
}
