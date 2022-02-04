
#include "../include/fdf.h"
#include "../libft/libft.h"
#include <math.h>

void    turn_x(int *y, int *z, double one)
{
    int mem_x;

    mem_x = *y;
    *y = mem_x *cos(one) + *z * sin(one);
    *z = -mem_x *sin(one) + *z * cos(one);
    //ft_putstr_fd("x \n",1);
}

void    turn_y(int *x, int *z, double two)
{
    int mem_y;

    mem_y = *x;
    *x = mem_y *cos(two) + *z * sin(two);
    *z = -mem_y *sin(two) + *z * cos(two);
    //ft_putstr_fd("y \n",1);

}

void    turn_z(int *x, int *y, double three)
{
    int mem_x;
    int mem_y;

    mem_x = *x;
    mem_y = *y;
    *x = mem_x *cos(three) - mem_y * sin(three);
    *y = mem_x *sin(three) + mem_y * cos(three);
    //ft_putstr_fd("z \n",1);

}

void    iso_preview(int *x, int *y, int z)
{
    int mem_x;
    int mem_y;

    mem_x = *x;
    mem_y = *y;
    *x = (mem_x - mem_y) * cos(0.523599);
    *y = -z + (mem_x + mem_y) *sin(0.523599);
}

t_pin screen(t_pin pin, t_fdf *fdf)
{
    pin.x *= fdf->cam->zoom;
    pin.y *= fdf->cam->zoom;
    pin.z *= fdf->cam->zoom / fdf->cam->z;
	pin.x -= (fdf->map->width * fdf->cam->zoom) / 2;
	pin.y -= (fdf->map->height * fdf->cam->zoom) / 2;
    ft_putnbr_fd(pin.y, 1);
	write(1,"\n",1);
    turn_x(&pin.y, &pin.z, fdf->cam->one);
    turn_y(&pin.x, &pin.z, fdf->cam->two);
    turn_z(&pin.x, &pin.z, fdf->cam->three);
    if (fdf->cam->proj == ISO)
        iso_preview(&pin.x, &pin.y, pin.z);
    pin.x += (WIDTH - MENU_WIDTH) /2 + fdf->cam->x + MENU_WIDTH;
    pin.y += (HEIGHT + fdf->map->height * fdf->cam->zoom) / 2 + fdf->cam->y;

    //ft_putnbr_fd(HEIGHT, 1);
	//write(1,"\n",1);
    return (pin);
}