#include "../include/error.h"
#include "../include/struct.h"
#include "../include/fdf.h"
#include "../minilibx/mlx.h"

t_fdf   *init_fdf(t_map *map)
{
    t_fdf *fdf;

    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    if (!( fdf = (t_fdf *)malloc(sizeof(t_fdf))))
        terminate(ERR_FDF);
    fdf->mlx = mlx_init();
    if (!(fdf->mlx))
        terminate(ERR_FDF);
    fdf->open = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf_windows");
    if (!(fdf->open))
        terminate(ERR_FDF);
    fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
    if (!(fdf->img))
        terminate(ERR_FDF);
    fdf->adress = mlx_get_data_addr(fdf->img, &(fdf->bit), &(fdf->line), &(fdf->endian));
    fdf->map = map;
    fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
    if (!(fdf->mouse))
        terminate(ERR_FDF);
    return (fdf);
}

t_cam    *init_cam(t_fdf *fdf)
{
    t_cam   *cam;

    cam = (t_cam *)malloc(sizeof(cam));
    if (!(cam))
        terminate(ERR_CAM);
    cam->zoom = FT_MIN((WIDTH - MENU_WIDTH) / fdf->map->width / 2, HEIGHT / fdf->map->height / 2);
    cam->one = 0;
    cam->two = 0;
    cam->three = 0;
    cam->x = 0;
    cam->y = 0;
    cam->z = 0;
    return (cam);
}

t_map   *init_map(void)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        terminate(ERR_INIT_MAP);
    map->width = 0;
    map->height = 0;
    map->coord = 0;
    map->colors = 0;
    map->min = FT_INT_MAX;
    map->max = FT_INT_MIN;
    map->size = 0;
    return (map);
}