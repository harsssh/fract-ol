/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:01:36 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/05 22:01:56 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
		unsigned char b)
{
	int	trgb;

	trgb = 0;
	trgb |= (t << 24);
	trgb |= (r << 16);
	trgb |= (g << 8);
	trgb |= b;
	return (trgb);
}
