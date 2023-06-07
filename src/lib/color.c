/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:01:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 00:07:55 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>

int	create_rgb(t_byte r, t_byte g, t_byte b)
{
	int	rgb;

	rgb = 0;
	rgb |= (r << 16);
	rgb |= (g << 8);
	rgb |= b;
	return (rgb);
}

static int	to_rgb(double r, double g, double b, double m)
{
	r = (r + m) * 255;
	g = (g + m) * 255;
	b = (b + m) * 255;
	return (create_rgb(r, g, b));
}

int	hsv_to_rgb(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	c = v * s;
	x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
	m = v - c;
	if (h >= 0 && h < 60)
		return (to_rgb(c, x, 0, m));
	else if (h >= 60 && h < 120)
		return (to_rgb(x, c, 0, m));
	else if (h >= 120 && h < 180)
		return (to_rgb(0, c, x, m));
	else if (h >= 180 && h < 240)
		return (to_rgb(0, x, c, m));
	else if (h >= 240 && h < 300)
		return (to_rgb(x, 0, c, m));
	else
		return (to_rgb(c, 0, x, m));
}
