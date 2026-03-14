/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:56:52 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 12:57:01 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	display_all(t_data *data)
{
	fractol(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	display_const(data);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = (unsigned)color;
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	add_mandel(t_data *data)
{
	if (data->fractal == MANDEL || data->fractal == BURNING)
	{
		data->c.a = data->z.a;
		if (data->fractal == BURNING)
			data->c.b = -data->z.b;
		else
			data->c.b = data->z.b;
		data->z.a = 0;
		data->z.b = 0;
	}
}

void	add_burning(t_data *data)
{
	if (data->fractal == BURNING)
	{
		if (data->z.a < 0)
			data->z.a = -data->z.a;
		if (data->z.b < 0)
			data->z.b = -data->z.b;
	}
}
