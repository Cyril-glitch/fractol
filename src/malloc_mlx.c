/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:56:26 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 12:56:41 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	malloc_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_data(data);
		exit(0);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FRACTOL");
	if (!data->win)
	{
		free_data(data);
		exit(0);
	}
	data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image.img)
	{
		free_data(data);
		exit(0);
	}
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
}
