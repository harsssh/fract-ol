/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:37:21 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 01:50:17 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "internal.h"
#include "mlx.h"

static int	get_offset(t_canvas *canvas, int x, int y)
{
	t_canvas_impl	*impl;

	impl = canvas->p_impl;
	return (y * impl->line_length + x * (impl->bits_per_pixel / 8));
}

void	put_pixel(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->p_impl->addr + get_offset(canvas, x, y);
	*(unsigned int *)dst = color;
}

void	render(t_canvas *canvas)
{
	t_canvas_impl	*impl;

	impl = canvas->p_impl;
	mlx_put_image_to_window(impl->mlx, impl->window, impl->img, 0, 0);
}

void	start(t_canvas *canvas)
{
	mlx_loop(canvas->p_impl->mlx);
}
