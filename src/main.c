/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:28:08 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 15:29:15 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/complex.h"
#include <stddef.h>
#include <stdio.h>

static void	init_event_handler(t_canvas_with_range *env)
{
	on_key_down(env->canvas, key_handler, env->canvas);
	on_destroy(env->canvas, terminate, env->canvas);
	on_mouse_use(env->canvas, mouse_handler, env);
}

static void	init_range(t_range *range)
{
	complex_set(&range->corner, DEFAULT_RE_MIN, DEFAULT_IM_MIN);
    range->length = DEFAULT_LENGTH;
}

static void init(t_canvas_with_range *env)
{
	init_range(&env->range);
	init_event_handler(env);
}

int	main(int ac, char **av)
{
	t_canvas_with_range env;

	(void)ac;
	env.canvas = new_canvas(WIDTH, HEIGHT, av[0]);
	if (env.canvas == NULL)
		return (1);
	init(&env);
	draw_mandelbrot_set(env.canvas, env.range, 64);
	put_pixel(env.canvas, env.canvas->width/2, env.canvas->height/2, 0x00FF0000);
	render(env.canvas);
	start(env.canvas);
	return (0);
}
