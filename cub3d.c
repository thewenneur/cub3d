#include "cub3d.h"

int main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	mlx = (t_mlx) {
		.mlx = mlx_init(),
		.img = (t_img) {}
	};
	if (!mlx.mlx)
		ft_quit(&mlx);
	mlx.img.data = mlx_xpm_file_to_image(mlx.mlx, "/Users/tbrouill/Desktop/RWBY-7.XPM", &mlx.img.width, &mlx.img.height);
	mlx.win = mlx_new_window(mlx.mlx, mlx.img.width, mlx.img.height, "RWBY");
	mlx_key_hook(mlx.win, &ft_keystroke, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, &ft_quit, &mlx);
	mlx_loop_hook(mlx.mlx, &ft_frame, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}