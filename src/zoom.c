/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:57:16 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 12:58:21 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	apply_zoom(t_data *data, double factor, int mouse_x, int mouse_y)
{
	double	ratio_x;
	double	ratio_y;
	double	new_widht;
	double	new_height;

	ratio_x = (double)mouse_x / WIDTH;
	ratio_y = (double)mouse_y / HEIGHT;
	data->math_map.width = data->math_map.max - data->math_map.min;
	data->math_map.height = data->math_map.max_i - data->math_map.min_i;
	new_widht = data->math_map.width * factor;
	new_height = data->math_map.height * factor;
	data->math_map.min = data->mouse.a - (new_widht * ratio_x);
	data->math_map.max = data->math_map.min + new_widht;
	data->math_map.max_i = data->mouse.b + (new_height * ratio_y);
	data->math_map.min_i = data->math_map.max_i - new_height;
}

int	mouse_hook(int bouton, int mouse_x, int mouse_y, t_data *data)
{
	px_to_complex(&data->mouse, data->math_map, mouse_x, mouse_y);
	if (bouton == 4)
	{
		apply_zoom(data, 0.95, mouse_x, mouse_y);
	}
	else if (bouton == 5)
	{
		apply_zoom(data, 1.05, mouse_x, mouse_y);
	}
	else if (bouton == 2)
	{
		data->math_map.min = -2;
		data->math_map.max = 2;
		data->math_map.min_i = -2;
		data->math_map.max_i = 2;
	}
	data->color_offset += 5;
	display_all(data);
	return (0);
}
