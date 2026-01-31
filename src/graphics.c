#include  "../inc/fractol.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void  my_put_square(t_image *image,  int color)
{
  int y;
  int x;

  y = 0;
  x = 0;
  while (y < HEIGHT)
  {
    x = 0;
    while (x < WIDTH)
    {
      my_mlx_pixel_put(image, x, y, color);
      x++;
    }
    y++;
  }
}

void  my_put_vector(t_image *image,int color)
{
  int y;
  int x;

  y = 0;
  x = 0;

  while (y < HEIGHT)
  {
    x = 0;
    while (x < WIDTH)
    {
      if (y == (HEIGHT / 2) || x == (WIDTH / 2))
        my_mlx_pixel_put(image, x, y, color);
      x++;
    }
    y++;
  }
}

void  my_put_graduation(t_image *image, int color)
{
  int y;
  int x;
  int vstep;
  int hstep;
  int size;

  x = 0;
  vstep = WIDTH / 8;
  hstep = HEIGHT / 8;
  size = 5;
  y = 0;
  while (y < HEIGHT)
  {
    x = 0;
    while (x < WIDTH)
    {
      if (((x % vstep == 0) && (y >= ((HEIGHT / 2) - size)) && (y <= ((HEIGHT / 2) + size))) ||( 
        (y % hstep == 0) && (x >= ((WIDTH / 2) - size)) && (x <= ((WIDTH / 2) + size))))
        my_mlx_pixel_put(image, x, y, color);
      x++;
    }
    y++;
  }
}
