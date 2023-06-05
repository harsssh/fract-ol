/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:05:25 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 02:41:24 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/color.h"
#include <stddef.h>

static size_t	count_diverged(double x0, double y0, size_t max_iter)
{
	size_t	i;
	double	xn;
	double	yn;
	double next_xn;
	double next_yn;

	xn = 0.0;
	yn = 0.0;
	i = 0;
	while (i < max_iter)
	{
		next_xn = xn * xn - yn * yn + x0;
		next_yn = 2.0 * xn * yn + y0;
		xn = next_xn;
		yn = next_yn;
		if (xn * xn + yn * yn > 4.0)
			return (i);
		i++;
	}
	return (max_iter);
}

void	draw_mandelbrot_set(t_canvas *canvas, t_range r, size_t max_iter)
{
	size_t			i;
	size_t			j;
	double			x;
	double			y;
	size_t			count;
	unsigned char	v;

	i = 0;
	while (i < (size_t)canvas->height)
	{
		y = r.y_min + (r.y_max - r.y_min) * i / canvas->height;
		j = 0;
		while (j < (size_t)canvas->width)
		{
			x = r.x_min + (r.x_max - r.x_min) * j / canvas->width;
			count = count_diverged(x, y, max_iter);
			v = count % 8 * 32;
			put_pixel(canvas, j, i, create_trgb(0, v, v, v));
			j++;
		}
		i++;
	}
}
