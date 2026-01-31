#include  "../inc/fractol.h"

static  t_complex *ft_xytoz(double x, double y, const char *set)
{
  (void)set;
  t_complex z;
  amp = 0;
  max = 0;
  min = 0;

  if (ft_strcmp(set, "Julia") == 0)
  {
    min = -2;
    max = 2;
    amp = max - min;
  }
  z.a = ((x / WIDTH) * amp) - end; 
  z.b = end - ((y / HEIGHT) * amp) 
  return  &z;
}

void ft_julia(t_image *image)
{


}
/*
a = ((x / WIDTH) * amp) - max;
b = max - ((y / HEIGHT) * amp);
*/

