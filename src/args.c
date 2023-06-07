/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemizuki <kemizuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:30:14 by kemizuki          #+#    #+#             */
/*   Updated: 2023/06/08 03:25:34 by kemizuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	print_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
}

static void	print_usage(void)
{
	print_error("Usage: fract-ol <fractal_type> [angle]\n");
	print_error("  fractal_type: Specify fractal type (mandelbrot or julia)\n");
	print_error("  angle:        Specify angle for Julia parameter (0-360)\n");
}

// Parses the given string to determine the fractal type
// and returns the corresponding fractal type (MANDELBROT or JULIA) if valid.
// Displays an error message and exits the program if invalid.
t_fractal	parse_fractal_type(char *s)
{
	if (ft_strcmp(s, "mandelbrot") == 0)
		return (MANDELBROT);
	if (ft_strcmp(s, "julia") == 0)
		return (JULIA);
	print_error("Invalid fractal_type. Available options: mandelbrot, julia\n");
	print_usage();
	exit(1);
}

// Parses the given string to determine the angle
// and returns the angle value (0-360) if it is valid.
// Displays an error message and exits the program if invalid.
int	parse_angle(char *s)
{
	size_t	len;
	int		angle;

	len = ft_strlen(s);
	if (len == 0 || len > 3 || (ft_strlen(s) > 1 && *s == '0'))
	{
		print_error("Invalid angle\n");
		print_usage();
		exit(1);
	}
	angle = ft_atoi(s);
	while (*s && ft_isdigit(*s))
		s++;
	if (angle < 0 || angle > 360 || *s != '\0')
	{
		print_error("Invalid angle\n");
		print_usage();
		exit(1);
	}
	return (angle);
}

void	validate_args(int argc, char **argv)
{
	t_fractal	type;

	if (argc < 2 || argc > 3)
	{
		print_error("Invalid number of arguments\n");
		print_usage();
		exit(1);
	}
	type = parse_fractal_type(argv[1]);
	if (type == MANDELBROT && argc >= 3)
	{
		print_error("Angle should not be specified for mandelbrot fractal\n");
		print_usage();
		exit(1);
	}
	else if (type == JULIA && argc < 3)
	{
		print_error("Missing angle for parameter in julia fractal\n");
		print_usage();
		exit(1);
	}
	else if (type == JULIA)
		parse_angle(argv[2]);
}
