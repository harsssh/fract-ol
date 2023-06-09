/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:37:55 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 02:44:18 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

void		complex_set(t_complex *z, double re, double im);
void		complex_add(t_complex *z, t_complex a);
void		complex_subtract(t_complex *z, t_complex a);
void		complex_from_polar(t_complex *z, double radius, double angle);
void		complex_scale(t_complex *z, t_complex center, double scale);

#endif
