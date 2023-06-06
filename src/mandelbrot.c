/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:05:25 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 01:32:40 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/color.h"
#include "lib/complex.h"
#include <math.h>
#include <stddef.h>

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

void	draw_mandelbrot_set(t_canvas *cv, t_range r, size_t max_iter)
{
	size_t			i;
	size_t			j;
	t_complex		z;
	size_t			count;
	unsigned char	v;

	i = 0;
	while (i < (size_t)cv->height)
	{
		j = 0;
		while (j < (size_t)cv->width)
		{
			complex_set(&z, convert_to_re(cv, r, j), convert_to_im(cv, r, i));
			count = count_diverged(z, max_iter);
			v = count % 8 * 32;
			put_pixel(cv, j, i, create_trgb(0, v, v, v));
			j++;
		}
		i++;
	}
}
