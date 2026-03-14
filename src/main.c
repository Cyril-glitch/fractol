/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:47:37 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 12:56:12 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	rules(void)
{
	ft_putstr("Use [mouse wheel] to zoom\n");
	ft_putstr("Use [mouse wheel click] to reset zoom\n");
	ft_putstr("Use [arrow keys] to move\n");
	ft_putstr("Use [a] and [d] to modify real part (c.a)\n");
	ft_putstr("Use [j] and [l] to modify imaginary part (c.b)\n");
	ft_putstr("Use [k] to reset constant C\n");
	ft_putstr("Press [ESC] to quit\n");
}

void	fractal_type(t_data *data)
{
	if (ft_strcmp("mandelbrot", data->set) == 0)
		data->fractal = MANDEL;
	else if (ft_strcmp("julia", data->set) == 0)
		data->fractal = JULIA;
	else if (ft_strcmp("burning", data->set) == 0)
		data->fractal = BURNING;
	else
	{
		ft_putstr("Error: Wrong arguments.\n \
            Usage:./fractol [mandelbrot | julia | burning]\n");
		exit(0);
	}
}

int	escape(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		free_data(data);
		exit(0);
	}
	return (0);
}

int	redcross(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_putstr("Error: Wrong arguments.\n \
            Usage: ./fractol [mandelbrot | julia | burning]\n");
		return (0);
	}
	data.set = av[1];
	fractal_type(&data);
	data.c.a = 0.285;
	data.c.b = 0.01;
	data.z.a = 0;
	data.z.b = 0;
	data.math_map.min = -2;
	data.math_map.max = 2;
	data.math_map.min_i = -2;
	data.math_map.max_i = 2;
	malloc_mlx(&data);
	rules();
	mlx_hook(data.win, 2, 1L << 0, keyboard, &data);
	mlx_hook(data.win, 17, 0, redcross, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	display_all(&data);
	mlx_loop(data.mlx);
}
