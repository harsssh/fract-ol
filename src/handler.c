/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:00:40 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 22:59:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"
#include "lib/keycode.h"
#include "lib/mousecode.h"
#include <stdlib.h>

int	terminate(t_context *ctx)
{
	clear_event_handler(ctx->canvas);
	free_canvas(ctx->canvas);
	exit(0);
}

int	key_handler(int keycode, t_context *ctx)
{
	if (keycode == KEY_ESCAPE)
		terminate(ctx);
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
	clear_image(ctx->canvas);
	ctx->draw_fractal(*ctx);
	render(ctx->canvas);
	return (0);
}
