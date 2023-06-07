/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:29:13 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 23:00:16 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 720
# define HEIGHT 720
# define DEFAULT_MAX_ITER 64
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
	double		length;
}				t_range;

typedef struct s_context
{
	t_canvas	*canvas;
	t_range		range;
	size_t		max_iter;
	t_complex	julia_param;
	void		(*draw_fractal)(struct s_context ctx);
}				t_context;

void			draw_mandelbrot_set(t_context ctx);
void			draw_julia_set(t_context ctx);

void			convert_to_complex(t_context ctx, t_complex *z, int x, int y);

int				key_handler(int keycode, t_context *ctx);
int				mouse_handler(int button, int x, int y, t_context *ctx);
int				terminate(t_context *ctx);

#endif
