/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:27:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 12:48:48 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/ft_complex.h"

double	transform_re(t_canvas *canvas, t_range r, int x)
{
	return (r.min.re + (r.max.re - r.min.re) * x / canvas->width);
}

double	transform_im(t_canvas *canvas, t_range r, int x)
{
	return (r.min.im + (r.max.im - r.min.im) * x / canvas->height);
}
