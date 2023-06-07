/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:24:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 14:48:45 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

void	complex_set(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
}

// z *= a
void	complex_product(t_complex *z, t_complex a)
{
	complex_set(z, z->re * a.re - z->im * a.im, z->re * a.im + z->im * a.re);
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
