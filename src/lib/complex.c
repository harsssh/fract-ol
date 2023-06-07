/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:24:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 02:44:58 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

void	complex_set(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
}

void	complex_subtract(t_complex *z, t_complex a)
{
	complex_set(z, z->re - a.re, z->im - a.im);
}

void	complex_add(t_complex *z, t_complex a)
{
	complex_set(z, z->re + a.re, z->im + a.im);
}

void	complex_scale(t_complex *z, t_complex center, double scale)
{
	complex_subtract(z, center);
	z->re *= scale;
	z->im *= scale;
	complex_add(z, center);
}

void	complex_from_polar(t_complex *z, double radius, double angle)
{
	z->re = radius * cos(angle);
	z->im = radius * sin(angle);
}
