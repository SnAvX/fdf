#include "../include/fdf.h"
#include "../include/keyboard.h"
#include "../include/struct.h"

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_3 || key == MAIN_PAD_3
		|| key == NUM_PAD_4 || key == MAIN_PAD_4
		|| key == NUM_PAD_6 || key == MAIN_PAD_6
		|| key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_8 || key == MAIN_PAD_8
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, fdf);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, fdf);
	return (0);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->press = true;
	return (0);
}


int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->press = false;
	return (0);
}


int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->mem_x = fdf->mouse->x;
	fdf->mouse->mem_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->press)
	{
		fdf->cam->two += (x - fdf->mouse->mem_x) * 0.002;
		fdf->cam->one += (y - fdf->mouse->mem_y) * 0.002;
		create(fdf->map, fdf);
	}
	return (0);
}

int		close(void *param)
{
	(void)param;
	exit(0);
}
