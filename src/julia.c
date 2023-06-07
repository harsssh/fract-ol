/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:05:25 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 22:59:49 by kemizuki         ###   ########.fr       */
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

static size_t	count_diverged(t_complex z, t_complex c, size_t max_iter)
{
	size_t	i;

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

void	draw_julia_set(t_context ctx)
{
	size_t			i;
	size_t			j;
	t_complex		z;
	size_t			count;
	unsigned char	v;

	i = 0;
	while (i < (size_t)ctx.canvas->height)
	{
		j = 0;
		while (j < (size_t)ctx.canvas->width)
		{
			convert_to_complex(ctx, &z, j, i);
			count = count_diverged(z, ctx.julia_param, ctx.max_iter);
			v = count % 8 * 32;
			put_pixel(ctx.canvas, j, i, create_rgb(v, v, v));
			j++;
		}
		i++;
	}
}
