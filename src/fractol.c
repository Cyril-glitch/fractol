#include "../inc/fractol.h"

int	main(void) {  
	void	*mlx;
	void	*mlx_win;
  int x;
  int y;

  x = 0;
  y = 0;
  t_image mlx_img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
  mlx_img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
  mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bits_per_pixel, &mlx_img.line_length, &mlx_img.endian);
 
  my_put_square(&mlx_img, 0xCCFFFF);
  my_put_vector(&mlx_img, 0x999999);
  my_put_graduation(&mlx_img, 0x999999);
  mlx_put_image_to_window(mlx, mlx_win, mlx_img.img, 0, 0);

	mlx_loop(mlx);
}
