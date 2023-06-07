/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:28:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 13:04:14 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"
#include <stddef.h>

static void init_event_handler(t_canvas *canvas)
{
	on_keydown(canvas, key_handler, canvas);
	on_destroy(canvas, terminate, canvas);
}

static void init_range(t_range *range)
{
	complex_set(&range->min, DEFAULT_RE_MIN, DEFAULT_IM_MIN);
	complex_set(&range->max, DEFAULT_RE_MAX, DEFAULT_IM_MAX);
}

int	main(int ac, char **av)
{
	t_canvas	*canvas;
	t_range		range;

	(void)ac;
	canvas = new_canvas(WIDTH, HEIGHT, av[0]);
	if (canvas == NULL)
		return (1);
	init_event_handler(canvas);
	init_range(&range);
	draw_mandelbrot_set(canvas, range, 64);
	render(canvas);
	start(canvas);
}
