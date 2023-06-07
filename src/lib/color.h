/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:58:24 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/07 23:45:10 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef unsigned char	t_byte;

int		create_rgb(t_byte r, t_byte g, t_byte b);
int		hsv_to_rgb(double h, double s, double v);

#endif
