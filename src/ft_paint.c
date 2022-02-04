#include "../include/error.h"
#include "../include/draw.h"
#include "../include/struct.h"
#include "../include/fdf.h"
#include "../libft/libft.h"

int colors(t_pin pos, t_pin start, t_pin finish, t_pin  vec)
{
    int green;
    int blue;
    int red;
    double  perc;


    if (pos.color == finish.color)
        return (pos.color);
    if (vec.x > vec.y)
        perc = percent(start.x, finish.x, pos.x);
    else
        perc = percent(start.y, finish.y, pos.y);
    red = gradient((start.color >> 16) & 0xFF, (finish.color >> 16) & 0xFF, perc);
    green = gradient((start.color >> 8) & 0xFF, (finish.color >> 8) & 0xFF, perc);
    blue = gradient(start.color & 0xFF, finish.color & 0xFF, perc);
    return ((red << 16) | (green << 8) | blue);

}

int default_color(int z, t_map *map)
{
    double perc;

    perc = percent(map->min, map->max, z);
    if (perc < 0.2)
        return (COLOR_PURPLE);
    else if (perc < 0.4)
        return (COLOR_RED);
    else if (perc < 0.6)
        return (COLOR_PINK);
    else if (perc < 0.8)
        return (COLOR_ORANGE);
    else
        return (COLOR_YELLOW);
}

int gradient(int start, int finish, double perc)
{
    return ((int)((1 - perc) * start + perc * finish));
}

