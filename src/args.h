/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 02:33:45 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 02:35:07 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "fractol.h"

t_fractal	parse_fractal_type(char *s);
int			parse_angle(char *s);
t_fractal	validate_args(int argc, char **argv);

#endif
