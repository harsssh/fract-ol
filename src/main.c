/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:28:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 00:14:22 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"
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

static void	init_context(t_context *ctx)
{
	ctx->max_iter = DEFAULT_MAX_ITER;
	ctx->draw_fractal = draw_julia_set;
	complex_set(&ctx->julia_param, -0.345, 0.654);
	init_range(&ctx->range);
	init_event_handler(ctx);
}

int	main(int ac, char **av)
{
	t_context	ctx;

	(void)ac;
	ctx.canvas = new_canvas(WIDTH, HEIGHT, av[0]);
	if (ctx.canvas == NULL)
		return (1);
	init_context(&ctx);
	ctx.draw_fractal(ctx);
	render(ctx.canvas);
	start(ctx.canvas);
	return (0);
}
