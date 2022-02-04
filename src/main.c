/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <plebiez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:46:57 by plebiez           #+#    #+#             */
/*   Updated: 2022/01/19 18:17:39 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"
#include "../include/struct.h"
#include "../include/fdf.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;
	t_map *map;
	t_fdf *fdf;
	t_coord *coord;

	errno = 0;
	coord = NULL;
	if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
		{
			terminate(ERR_FD);
		}
		map = init_map();
		if (read_map(fd, &coord, map) == -1)
			terminate(ERR_READ);
		fdf = init_fdf(map);
		array_convert(&coord, map);
		fdf->cam = init_cam(fdf);
		create(fdf->map, fdf);
		write(1, "0\n", 3);
		control(fdf);
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_FORM);
	return (0);
}

