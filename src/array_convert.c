#include "../include/fdf.h"
#include "../include/struct.h"
#include "../include/error.h"
#include "../libft/libft.h"

void    array_convert(t_coord **coord, t_map *map)
{
    t_coord *save;
    size_t  i;
    size_t  size;

    size = map->width * map->height * sizeof(int);
    if (!(map->coord = (int *)malloc(sizeof(size))))
        terminate(ERR_CONV);
    if (!(map->colors = (int *)malloc(sizeof(size))))
        terminate(ERR_CONV);
    i = map->width * map->height - 1;
    while ((save = top(coord)) && i >= 0)
    {
        map->coord[i] = save->z;
        map->colors[i] = save->color;
        if (save->z > map->max)
            map->max = save->z;
        if (save->z < map->min)
            map->min = save->z;
        i--;
        free(save);
    }
    map->size = map->max - map->min;
}