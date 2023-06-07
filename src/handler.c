/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:00:40 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 17:39:00 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"
#include "lib/keycode.h"
#include "lib/mousecode.h"
#include <stdio.h>
#include <stdlib.h>

int	terminate(t_canvas *canvas)
{
	clear_event_handler(canvas);
	free_canvas(canvas);
	exit(0);
}

int	key_handler(int keycode, t_canvas *canvas)
{
	if (keycode == KEY_ESCAPE)
		terminate(canvas);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_canvas_with_range *env)
{
	double		scale;
    t_complex   center;
    t_complex   diff;

	if (button == MOUSE_SCROLL_UP)
		scale = 1 / SCALE_FACTOR;
	else if (button == MOUSE_SCROLL_DOWN)
		scale = SCALE_FACTOR;
	else
		return (0);

    complex_set(&center, convert_to_re(env->canvas, env->range, x),
                convert_to_im(env->canvas, env->range, y));
    complex_set(&diff, center.re, center.im);
    complex_subtract(&diff, env->range.corner);

    complex_scale(&env->range.corner, center, scale);
    complex_subtract(&env->range.corner, diff);

	clear_image(env->canvas);
	draw_mandelbrot_set(env->canvas, env->range, 64);
	render(env->canvas);
	return (0);
}
