/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:40:46 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/05 22:38:15 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

struct	s_canvas_impl;

typedef struct s_canvas
{
	struct s_canvas_impl	*p_impl;
	int						width;
	int						height;
}							t_canvas;

t_canvas	*new_canvas(int width, int height, char *title);
void		free_canvas(t_canvas *canvas);
void		put_pixel(t_canvas *canvas, int x, int y, int color);
void		render(t_canvas *canvas);
void		start(t_canvas *canvas);

#endif
