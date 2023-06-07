/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:29:13 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 14:55:46 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 720
# define HEIGHT 720
# define DEFAULT_RE_MIN -2.0
# define DEFAULT_IM_MIN -2.0
# define DEFAULT_LENGTH 4.0
# define SCALE_FACTOR 1.2

# include "lib/canvas.h"
# include "lib/complex.h"
# include <stddef.h>

typedef struct s_range
{
	t_complex	corner;
    double      length;
}				t_range;

typedef struct s_canvas_with_range
{
	t_canvas	*canvas;
	t_range		range;
} t_canvas_with_range;

void	draw_mandelbrot_set(t_canvas *cv, t_range r, size_t max_iter);
void	draw_julia_set(t_canvas *cv, t_range r, t_complex c, size_t max_iter);

double	convert_to_re(t_canvas *canvas, t_range r, int x);
double	convert_to_im(t_canvas *canvas, t_range r, int y);

int		key_handler(int keycode, t_canvas *canvas);
int		mouse_handler(int button, int x, int y, t_canvas_with_range *param);
int		terminate(t_canvas *canvas);

#endif
