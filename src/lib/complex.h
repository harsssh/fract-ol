/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:37:55 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 14:48:38 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

# include <math.h>

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

void		complex_set(t_complex *z, double re, double im);
void		complex_add(t_complex *z, t_complex a);
void		complex_subtract(t_complex *z, t_complex a);
void		complex_product(t_complex *z, t_complex a);
void		complex_scale(t_complex *z, t_complex center, double scale);

#endif
