#include "../include/error.h"
#include "../include/draw.h"
#include "../include/struct.h"
#include "../include/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <errno.h>

t_pin   next_point(int x, int y, t_map *map)
{
    t_pin p;
    int     mem;

    mem = ft_index(x, y, map->width);
    p.x = x;
    p.y = y;
    p.z = map->coord[mem];
    p.color = (map->colors[mem] == -1) ? default_color(p.z, map) : map->colors[mem];
    return (p);

}
/*
----------------REDUCTION ?---------------------------------
*/
int ft_index(int x, int y, int width)
{
    return (y * width + x);
}

void    terminate(char *c)
{
    if (errno == 0)
        ft_putendl_fd(c, 2);
    else
        perror(c);
    exit(1);
}

double	percent(int start, int finish, int p)
{
	double	place;
	double	dist;

	place = p - start;
	dist = finish - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}