/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:27:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/11 13:57:04 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"

static double	to_re(t_context ctx, int x)
{
	return (ctx.range.corner.re + x * ctx.range.length / ctx.canvas->width);
}

static double	to_im(t_context ctx, int y)
{
	return (ctx.range.corner.im + y * ctx.range.length / ctx.canvas->height);
}

void	convert_to_complex(t_context ctx, t_complex *z, int x, int y)
{
	complex_set(z, to_re(ctx, x), to_im(ctx, y));
}

void	redraw(t_context ctx)
{
	ctx.draw_fractal(ctx);
	render(ctx.canvas);
}
