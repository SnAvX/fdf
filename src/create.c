#include "../include/error.h"
#include "../include/draw.h"
#include "../include/struct.h"
#include "../include/fdf.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>

void	pixel(t_fdf *fdf, int x, int y, int color)
{
	int j;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		j = (x * fdf->bit / 8) + (y * fdf->line);
		fdf->adress[j] = color;
		fdf->adress[j++] = color >> 8;
		fdf->adress[j++] = color >> 16;
	}
}
static void	line(t_pin f, t_pin s, t_fdf *fdf)
{
	t_pin	delta;
	t_pin	sign;
	t_pin	cur;
	int		error[2];

	/*ft_putnbr_fd(s.x, 1);
	write(1,"\n",1);
    ft_putnbr_fd(f.x, 1);
	write(1,"\n",1);*/
	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		pixel(fdf, cur.x, cur.y, colors(cur, f, s, delta));
		//ft_putstr_fd("t \n", 1);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

/*
void    line(t_pin u, t_pin v, t_fdf *fdf)
{
    t_pin   vec;
    t_pin   op;
    t_pin   cut;
    int     fail[2];

    vec.x = FT_ABS(v.x - u.x);
//    ft_putnbr_fd(vec.x, 1, 1);
//	ft_putchar_fd('\n', 1);
    ft_putnbr_fd(vec.y, 1,1);
	ft_putchar_fd('\n', 1);
    vec.y = FT_ABS(v.y - u.y);
    ft_putnbr_fd(vec.y, 1,1);
	ft_putchar_fd('\n', 1);
    op.x = u.x < v.x ? 1 : -1;
    op.y = u.y < v.y ? 1 : -1;
    fail[0] = vec.x - vec.y;
    cut = u;
    while (cut.x != v.x || cut.y != v.y)
    {
        pixel(fdf, cut.x, cut.y, colors(cut, u, v, vec));
        if ((fail[1] = fail[0] * 2) > -vec.y)
        {
            fail[0] -= vec.y;
            cut.x += op.x;
        }
        if (fail[1] < vec.x)
        {
            fail[0] += vec.x;
            cut.y += op.y;
        }
    }
    
}
*/
void    background(t_fdf *fdf)
{
    int i;
    int *img;

    ft_bzero(fdf->adress, (fdf->bit / 8) * WIDTH * HEIGHT);
    img = (int *)(fdf->adress);
    i = 0;
    while (i < WIDTH * HEIGHT)
    {
        if (!(i % WIDTH < MENU_WIDTH))
            img[i] = MENU_BACKGROUND_COLOR;
        else
            img[i] = BACKGROUND_COLOR;
        i++;
    }
}

void    create(t_map *map, t_fdf *fdf)
{
    int x;
    int y;

    background(fdf);
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (x != fdf->map->width - 1)
                line(screen(next_point(x, y, map), fdf), screen(next_point(x + 1, y , map), fdf),fdf);
            if (y != fdf->map->height -1)
				line(screen(next_point(x, y, map), fdf), screen(next_point(x, y + 1, map), fdf), fdf);
			x++;
        }
        y++;
    }
    //ft_putstr_fd("t \n",1);
    mlx_put_image_to_window(fdf->mlx, fdf->open, fdf->img, 0, 0);
	print_menu(fdf);
}