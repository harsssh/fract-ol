/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:28:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 03:33:22 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"
#include <math.h>
#include <stddef.h>

static void	init_event_handler(t_context *ctx)
{
	on_key_down(ctx->canvas, key_handler, ctx);
	on_mouse_use(ctx->canvas, mouse_handler, ctx);
	on_destroy(ctx->canvas, terminate, ctx);
}

static void	init_range(t_range *range)
{
	complex_set(&range->corner, DEFAULT_RE_MIN, DEFAULT_IM_MIN);
	range->length = DEFAULT_LENGTH;
}

static void	init_context(t_context *ctx, t_fractal type, unsigned int angle)
{
	double	angle_rad;

	if (type == MANDELBROT)
		ctx->draw_fractal = draw_mandelbrot_set;
	else if (type == JULIA)
		ctx->draw_fractal = draw_julia_set;
	ctx->max_iter = DEFAULT_MAX_ITER;
	angle_rad = (double)angle / 180.0 * M_PI;
	complex_from_polar(&ctx->julia_param, JULIA_PRAM_RADIUS, angle_rad);
	init_range(&ctx->range);
	init_event_handler(ctx);
}

int	main(int argc, char **argv)
{
	t_context		ctx;
	t_fractal		type;
	unsigned int	angle;

	validate_args(argc, argv);
	type = parse_fractal_type(argv[1]);
	if (type == JULIA)
		angle = parse_angle(argv[2]);
	ctx.canvas = new_canvas(WIDTH, HEIGHT, argv[0]);
	if (ctx.canvas == NULL)
		return (1);
	init_context(&ctx, type, angle);
	ctx.draw_fractal(ctx);
	render(ctx.canvas);
	start(ctx.canvas);
	return (0);
}
