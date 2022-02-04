#ifndef STRUCT_H

#define STRUCT_H

typedef enum
{
    ISO,
    PARALLEL
}   t_proj;

typedef enum
{
	false,
	true
}	t_bool;

typedef struct s_mouse
{
    char    press;
    int     x;
    int     y;
    int     mem_x;
    int     mem_y;
}   t_mouse;

typedef struct s_cam
{
    t_proj  proj;
    double  one;
    double  two;
    double  three;
    float   z;
    int     x;
    int     y;
    int     zoom;
}   t_cam;

typedef struct s_coord
{
    int z;
    int color;
    struct s_coord *mem;
}   t_coord;

typedef struct s_map
{
	int	width;
	int	height;
	int max;
	int min;
	int	*coord;
	int *colors;
	int size;
}	t_map;

typedef struct s_pin
{
    int x;
    int y;
    int z;
    int color;
}   t_pin;

typedef struct s_fdf
{
    void    *img;
    void    *mlx;
    void    *open;
    char    *adress;
    int     bit;
    int     line;
    int     endian;
    t_map   *map;
    t_mouse *mouse;
    t_cam   *cam;
}   t_fdf;
#endif