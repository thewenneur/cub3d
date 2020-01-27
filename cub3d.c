#include "cub3d.h"

int main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx = ft_mlx_init(argc, argv);
	mlx_key_hook(mlx.win, &ft_keystroke, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, &ft_quit, &mlx);
	mlx_loop_hook(mlx.mlx, &ft_frame, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}