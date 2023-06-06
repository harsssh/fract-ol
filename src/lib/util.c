/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:28:06 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 01:55:40 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "internal.h"
#include "libft.h"
#include "mlx.h"

void	get_mouse_position(t_canvas *canvas, int *x, int *y)
{
	mlx_mouse_get_pos(canvas->p_impl->window, x, y);
}

void	clear_image(t_canvas *canvas)
{
	size_t	n;

	n = canvas->height * canvas->p_impl->line_length + canvas->width
		* (canvas->p_impl->bits_per_pixel / 8);
	ft_bzero(canvas->p_impl->addr, n);
}
