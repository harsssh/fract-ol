/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:29:13 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 02:22:07 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 720
# define HEIGHT 720

# include "lib/canvas.h"
# include <stddef.h>

typedef struct s_range {
	double x_min;
	double x_max;
	double y_min;
	double y_max;
} t_range;

void	draw_mandelbrot_set(t_canvas *canvas, t_range r, size_t max_iter);

#endif
