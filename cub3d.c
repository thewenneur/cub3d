#include "cub3d.h"

int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "LOL C UN TEST");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}