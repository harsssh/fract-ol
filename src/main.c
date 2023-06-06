/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:28:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 21:55:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/ft_complex.h"
#include <stddef.h>

int	main(int ac, char **av)
{
	t_canvas	*canvas;
	t_range		range;
	t_complex	c;

	(void)ac;
	canvas = new_canvas(WIDTH, HEIGHT, av[0]);
	if (canvas == NULL)
		return (1);
	handle_key_event(canvas, key_handler, canvas);
	handle_close_event(canvas, close_window, canvas);
	complex_set(&range.min, -2.0, -2.0);
	complex_set(&range.max, 2.0, 2.0);
	complex_set(&c, -0.8, 0.15);
	draw_mandelbrot_set(canvas, range, 64);
	//draw_julia_set(canvas, range, c, 64);
	render(canvas);
	start(canvas);
}
