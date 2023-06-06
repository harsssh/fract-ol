/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:29:13 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 01:44:32 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 720
# define HEIGHT 720
# define DEFAULT_RE_MIN -2.0
# define DEFAULT_RE_MAX 2.0
# define DEFAULT_IM_MIN -2.0
# define DEFAULT_IM_MAX 2.0

# include "lib/canvas.h"
# include "lib/complex.h"
# include <stddef.h>

typedef struct s_range
{
	t_complex	min;
	t_complex	max;
}				t_range;

void	draw_mandelbrot_set(t_canvas *cv, t_range r, size_t max_iter);
void	draw_julia_set(t_canvas *cv, t_range r, t_complex c, size_t max_iter);

double	convert_to_re(t_canvas *canvas, t_range r, int x);
double	convert_to_im(t_canvas *canvas, t_range r, int y);
void	get_mouse_complex_coord(t_canvas *canvas, t_range r, t_complex *z);

int		key_handler(int keycode, t_canvas *canvas);
int		terminate(t_canvas *canvas);

#endif
