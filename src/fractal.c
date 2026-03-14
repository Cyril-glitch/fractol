/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:49:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 14:01:20 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	px_to_complex(t_complex *z, t_math_map math_map, int x, int y)
{
	math_map.width = math_map.max - math_map.min;
	math_map.height = math_map.max_i - math_map.min_i;
	z->a = math_map.min + ((double)x / WIDTH) * math_map.width;
	z->b = math_map.max_i - ((double)y / HEIGHT) * math_map.height;
}

double	ft_escape_life(t_data *data)
{
	int		n;
	double	aa;
	double	bb;

	n = 0;
	while (n < MAX_ITER)
	{
		add_burning(data);
		aa = data->z.a * data->z.a;
		bb = data->z.b * data->z.b;
		if (aa + bb > 4.0)
			return (n + 1 - log(log(aa + bb)) / log(2));
		data->z.b = 2.0 * data->z.b * data->z.a + data->c.b;
		data->z.a = aa - bb + data->c.a;
		n++;
	}
	return (MAX_ITER);
}

static int	ft_interpolate(int start_color, int end_color, double life_ratio)
{
	int	amp;

	amp = end_color - start_color;
	return (start_color + (amp * life_ratio));
}

unsigned int	ft_color(double life, t_data *data)
{
	double				life_ratio;
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
	static unsigned int	color;

	r = 0;
	g = 0;
	b = 0;
	life_ratio = (life / (double)MAX_ITER);
	if (life == (double)MAX_ITER)
		return (0xFFFFFF);
	r |= (ft_interpolate(0, 50, life_ratio) << 16);
	g |= (ft_interpolate(0, 200, life_ratio) << 8);
	b |= ft_interpolate(0, 255, life_ratio);
	r ^= ((data->color_offset % 256) << 16);
	g ^= ((data->color_offset % 256) << 8);
	b ^= (data->color_offset % 256);
	color = (r | g | b) ^ data->color_offset;
	return (color);
}

void	fractol(t_data *data)
{
	double	life;

	data->p.y = 0;
	data->p.x = 0;
	while (data->p.y < HEIGHT)
	{
		data->p.x = 0;
		while (data->p.x < WIDTH)
		{
			px_to_complex(&data->z, data->math_map, data->p.x, data->p.y);
			add_mandel(data);
			life = ft_escape_life(data);
			my_mlx_pixel_put(&data->image, data->p.x, data->p.y, ft_color(life, \
						data));
			data->p.x++;
		}
		data->p.y++;
	}
}
