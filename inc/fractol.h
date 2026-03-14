/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:45:39 by cycolonn          #+#    #+#             */
/*   Updated: 2026/02/10 14:09:36 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>

# define HEIGHT 700

# define WIDTH 700

# define MAX_ITER 40

enum			e_type
{
	MANDEL,
	JULIA,
	BURNING
};

typedef struct s_image
{
	void		*img;
	char		*addr;

	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_complex
{
	double		a;
	double		b;
}				t_complex;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_math_map
{
	double		min;
	double		max;
	double		min_i;
	double		max_i;
	double		width;
	double		height;
}				t_math_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			color_offset;
	char		*set;
	enum e_type	fractal;
	t_image		image;
	t_complex	z;
	t_complex	c;
	t_complex	mandel;
	t_complex	mouse;
	t_math_map	math_map;
	t_position	p;
}				t_data;

//utils
void			free_data(t_data *data);
void			malloc_mlx(t_data *data);
void			display_all(t_data *data);
void			rules(void);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
void			add_burning(t_data *data);
void			add_mandel(t_data *data);

//fractal
void			px_to_complex(t_complex *z, t_math_map math_map, int x, int y);
double			ft_escape_life(t_data *data);
unsigned int	ft_color(double life, t_data *data);
void			fractol(t_data *data);

//hook
int				escape(int keycode, t_data *data);
int				redcross(t_data *data);
int				mouse_hook(int bouton, int x, int y, t_data *data);
int				keyboard(int keycode, t_data *data);
void			display_const(t_data *data);
void			change_const(int keycode, t_data *data);

#endif
