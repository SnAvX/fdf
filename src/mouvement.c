#include "../include/keyboard.h"
#include "../include/fdf.h"
#include "../include/fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		fdf->cam->zoom++;
	else if (key == NUM_PAD_MINUS ||
		key == MAIN_PAD_MINUS ||
		key == MOUSE_SCROLL_DOWN)
		fdf->cam->zoom--;
	if (fdf->cam->zoom < 1)
		fdf->cam->zoom = 1;
	create(fdf->map, fdf);
}

/*
** Move map
*/

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->cam->x -= 10;
	else if (key == ARROW_RIGHT)
		fdf->cam->x += 10;
	else if (key == ARROW_UP)
		fdf->cam->y -= 10;
	else
		fdf->cam->y += 10;
	create(fdf->map, fdf);
}

/*
** Rotate map
*/

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		fdf->cam->one += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		fdf->cam->one -= 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		fdf->cam->two -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		fdf->cam->two += 0.05;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_3 || key == MAIN_PAD_3)
		fdf->cam->three += 0.05;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		fdf->cam->three -= 0.05;
	create(fdf->map, fdf);
}

/*
** Change z value. Make map more flatten
*/

void	flatten(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_LESS)
		fdf->cam->z -= 0.1;
	else if (key == MAIN_PAD_MORE)
		fdf->cam->z += 0.1;
	if (fdf->cam->z < 0.1)
		fdf->cam->z = 0.1;
	else if (fdf->cam->z > 10)
		fdf->cam->z = 10;
	create(fdf->map, fdf);
}

/*
** Change projection type
*/

void	change_projection(int key, t_fdf *fdf)
{
	fdf->cam->one = 0;
	fdf->cam->two = 0;
	fdf->cam->three = 0;
	if (key == MAIN_PAD_I)
		fdf->cam->proj = ISO;
	else if (key == MAIN_PAD_P)
		fdf->cam->proj = PARALLEL;
	create(fdf->map, fdf);
}