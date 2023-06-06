/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:29:13 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 00:57:29 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 720
# define HEIGHT 720

# include "lib/canvas.h"
# include "lib/ft_complex.h"
# include <stddef.h>

typedef struct s_range
{
	t_complex	min;
	t_complex	max;
}				t_range;

void	draw_mandelbrot_set(t_canvas *cv, t_range r, size_t max_iter);
void	draw_julia_set(t_canvas *cv, t_range r, t_complex c, size_t max_iter);

double	transform_re(t_canvas *canvas, t_range r, int x);
double	transform_im(t_canvas *canvas, t_range r, int x);

int		key_handler(int keycode, t_canvas *canvas);
int		terminate(t_canvas *canvas);

#endif
