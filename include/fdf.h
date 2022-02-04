/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <plebiez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:38:18 by plebiez           #+#    #+#             */
/*   Updated: 2022/01/19 18:15:32 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../include/error.h"
#include "../include/draw.h"
#include "../include/struct.h"

#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# define FT_ULONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_ULONG_MAX >> 1))
# define FT_LONG_MIN	((long)(~FT_LONG_MAX))

# define FT_UINT_MAX	((unsigned)(~0L))
# define FT_INT_MAX		((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN		((int)(~FT_INT_MAX))

t_map   *init_map(void);
t_fdf   *init_fdf(t_map *map);
t_coord *top(t_coord **coord);
t_cam   *init_cam(t_fdf *fdf);
t_pin 	screen(t_pin pin, t_fdf *fdf);
t_bool	ft_isnumber(char *str, int base);
t_pin   next_point(int x, int y, t_map *map);
int		mouse_press(int button, int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int 	close_it(void *param);
int		key_press(int key, void *param);
int		read_map(int fd, t_coord **coord, t_map *map);
int		colors(t_pin pos, t_pin start, t_pin finish, t_pin  vec);
int		default_color(int z, t_map *map);
int     gradient(int finish, int start, double perc);
int     ft_index(int x, int y, int width);
void    create(t_map *map, t_fdf *fdf);
void	zoom(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void    terminate(char *c);
void    array_convert(t_coord **coord, t_map *map);
void    control(t_fdf *fdf);
void	print_menu(t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	flatten(int key, t_fdf *fdf);
void	change_projection(int key, t_fdf *fdf);
void	push(t_coord **coords, t_coord *new);
double	percent(int start, int finish, int p);



#endif 
