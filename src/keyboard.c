/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:50:18 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 12:50:32 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	up(double step, t_data *data)
{
	data->math_map.min_i += (data->math_map.height * step);
	data->math_map.max_i += (data->math_map.height * step);
}

static void	down(double step, t_data *data)
{
	data->math_map.min_i -= (data->math_map.height * step);
	data->math_map.max_i -= (data->math_map.height * step);
}

static void	right(double step, t_data *data)
{
	data->math_map.min += (data->math_map.width * step);
	data->math_map.max += (data->math_map.width * step);
}

static void	left(double step, t_data *data)
{
	data->math_map.min -= (data->math_map.width * step);
	data->math_map.max -= (data->math_map.width * step);
}

int	keyboard(int keycode, t_data *data)
{
	double	step;

	step = 0.1;
	if (!data)
		return (1);
	data->math_map.width = data->math_map.max - data->math_map.min;
	data->math_map.height = data->math_map.max_i - data->math_map.min_i;
	escape(keycode, data);
	change_const(keycode, data);
	if (keycode == XK_Up)
		up(step, data);
	if (keycode == XK_Down)
		down(step, data);
	if (keycode == XK_Right)
		right(step, data);
	if (keycode == XK_Left)
		left(step, data);
	display_all(data);
	return (0);
}
/*
   1/on recuper amplitude reel et imaginaire
   2/on creer un pourcentage de ces valeur en multipliant par un padding step
   3/on addition avec les valeur des extremites mathematique de la map
*/
