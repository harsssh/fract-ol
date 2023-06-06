/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:00:40 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/06 22:07:19 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib/canvas.h"
#include "lib/keycode.h"
#include <stdio.h>
#include <stdlib.h>

int	close_window(t_canvas *canvas)
{
	free_canvas(canvas);
	exit(0);
}

int	key_handler(int keycode, t_canvas *canvas)
{
	if (keycode == KEY_ESCAPE)
		close_window(canvas);
	return (0);
}
