/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:27:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 14:38:30 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"

double	convert_to_re(t_canvas *canvas, t_range r, int x)
{
	return (r.min.re + (r.max.re - r.min.re) * x / canvas->width);
}

double	convert_to_im(t_canvas *canvas, t_range r, int y)
{
	return (r.min.im + (r.max.im - r.min.im) * y / canvas->height);
}

