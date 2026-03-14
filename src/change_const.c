/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_const.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:49:39 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 12:49:41 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	display_const(t_data *data)
{
	char	*reel;
	char	*imaginaire;

	reel = ft_dtoa(data->c.a, 3);
	imaginaire = ft_dtoa(data->c.b, 3);
	if (!reel || !imaginaire)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	mlx_string_put(data->mlx, data->win, 20, 10, 0xFFFFFF, "C = ");
	mlx_string_put(data->mlx, data->win, 60, 10, 0xFFFFFF, reel);
	mlx_string_put(data->mlx, data->win, 100, 10, 0xFFFFFF, " + ");
	mlx_string_put(data->mlx, data->win, 130, 10, 0xFFFFFF, imaginaire);
	free(reel);
	free(imaginaire);
}

void	change_const(int keycode, t_data *data)
{
	if (keycode == XK_d && data->c.a < 2)
		data->c.a += 0.005;
	else if (keycode == XK_a && data->c.a > -2)
		data->c.a -= 0.005;
	else if (keycode == XK_l && data->c.b < 2)
		data->c.b += 0.005;
	else if (keycode == XK_j && data->c.b > -2)
		data->c.b -= 0.005;
	else if (keycode == XK_k)
	{
		data->c.a = 0;
		data->c.b = 0;
	}
}
