#include "../include/fdf.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

void control(t_fdf *fdf)
{
    mlx_hook(fdf->open, 2, 0, key_press, fdf);
	mlx_hook(fdf->open, 17, 0, close_it, fdf);
	mlx_hook(fdf->open, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->open, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->open, 6, 0, mouse_move, fdf);
}

int close_it(void *param)
{
    (void)param;
    exit(0);
}