/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:05:25 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 23:44:04 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/color.h"
#include "lib/complex.h"

static double	next_re(t_complex z, t_complex c)
{
	return (z.re * z.re - z.im * z.im + c.re);
}

static double	next_im(t_complex z, t_complex c)
{
	return (2 * z.re * z.im + c.im);
}

static size_t	count_diverged(t_complex c, size_t max_iter)
{
	size_t		i;
	t_complex	z;

	complex_set(&z, 0, 0);
	i = 0;
	while (i < max_iter)
	{
		complex_set(&z, next_re(z, c), next_im(z, c));
		if (z.re * z.re + z.im * z.im > 4.0)
			return (i);
		i++;
	}
	return (max_iter);
}

static double	calc_hue(size_t count, size_t max_iter)
{
	return (fmod((double)count / (double)max_iter * 360.0 + 230.0, 360));
}

void	draw_mandelbrot_set(t_context ctx)
{
	size_t		i;
	size_t		j;
	t_complex	z;
	double		hue;
	int			color;

	i = 0;
	while (i < (size_t)ctx.canvas->height)
	{
		j = 0;
		while (j < (size_t)ctx.canvas->width)
		{
			convert_to_complex(ctx, &z, j, i);
			hue = calc_hue(count_diverged(z, ctx.max_iter), ctx.max_iter);
			color = hsv_to_rgb(hue, COLOR_SATURATION, COLOR_VALUE);
			put_pixel(ctx.canvas, j, i, color);
			j++;
		}
		i++;
	}
}
