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
	return (r.corner.re + x * r.length / canvas->width);
}

double	convert_to_im(t_canvas *canvas, t_range r, int y)
{
	return (r.corner.im + y * r.length / canvas->height);
}

