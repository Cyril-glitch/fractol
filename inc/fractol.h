#ifndef FRACTOL_H
# define FRACTOL_H

# include  "../mlx_linux/mlx.h"
# include  "../libft/inc/libft.h"
# include  "../libft/inc/ft_printf.h"

# define  HEIGHT 1080
# define  WIDTH  1920

typedef struct  s_image
{
  void  *img;
  char  *addr;

  int   bits_per_pixel;
  int   line_length;
  int   endian;
} t_image;

typedef struct  s_complex
{
  double a;
  double  b;
} t_complex;


void  my_put_square(t_image *image, int color);
void  my_put_vector(t_image *image, int color);
void  my_put_graduation(t_image *image, int color);


#endif
