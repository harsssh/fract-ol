/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:50:26 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 01:49:45 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "internal.h"
#include <mlx.h>
#include <stdlib.h>

static void	set_image_and_window(t_canvas_impl *impl, int w, int h, char *title)
{
	impl->img = mlx_new_image(impl->mlx, w, h);
	if (impl->img != NULL)
		impl->addr = mlx_get_data_addr(impl->img, &impl->bits_per_pixel,
				&impl->line_length, &impl->endian);
	impl->window = mlx_new_window(impl->mlx, w, h, title);
}

static t_canvas_impl	*new_canvas_impl(int w, int h, char *title)
{
	t_canvas_impl	*impl;

	impl = (t_canvas_impl *)malloc(sizeof(t_canvas_impl));
	if (impl == NULL)
		return (NULL);
	impl->mlx = mlx_init();
	if (impl->mlx == NULL)
	{
		free(impl);
		return (NULL);
	}
	set_image_and_window(impl, w, h, title);
	if (impl->img == NULL || impl->window == NULL)
	{
		free(impl->img);
		free(impl->window);
		free(impl->mlx);
		free(impl);
		return (NULL);
	}
	return (impl);
}

t_canvas	*new_canvas(int width, int height, char *title)
{
	t_canvas		*canvas;
	t_canvas_impl	*impl;

	impl = new_canvas_impl(width, height, title);
	if (impl == NULL)
		return (NULL);
	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	if (canvas == NULL)
		return (NULL);
	canvas->p_impl = impl;
	canvas->height = height;
	canvas->width = width;
	return (canvas);
}

void	free_canvas(t_canvas *canvas)
{
	mlx_destroy_window(canvas->p_impl->mlx, canvas->p_impl->window);
	mlx_destroy_image(canvas->p_impl->mlx, canvas->p_impl->img);
	free(canvas->p_impl);
	free(canvas);
}

