
#include "../include/error.h"
#include "../include/struct.h"
#include "../libft/libft.h"
#include "../include/fdf.h"

static void	free_all(char **clear)
{
	size_t i;

	i = 0;
	while (clear[i])
		free(clear[i++]);
	free(clear);	
}

void	ft_strdel(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

static t_coord *new_cord(char *c)
{
	t_coord	*coord;
	char	**parts;

	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		terminate(ERR_READ);
	if (!(parts = ft_split(c, ',')))
		terminate(ERR_READ);
	if (!ft_isnumber(parts[0], 10))
		terminate(ERR_READ);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		terminate(ERR_READ);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->mem = NULL;
	free_all(parts);
	return (coord);
}

void	line_parcing(char **tab, t_coord **coord, t_map *map)
{
	int width;

	width = 0;
	while (*tab)
	{
		push(coord, new_cord(*(tab++)));
		width++;
	}
	if (map->height == 0)
	{
		map->width = width;
	}
	else if (map->width != width)
	{
		terminate(ERR_FD);
	}
}

int    read_map(const int fd, t_coord **coord, t_map *map)
{
	char	*str;
	int		result;
	char	**tab;

	while ((result = get_next_line(fd, &str)) == 1)
	{
		if (!(tab = ft_split(str, ' ')))
			terminate(ERR_READ);
		
		line_parcing(tab, coord, map);
		free_all(tab);
		ft_strdel(&str);
		map->height++;
	}
	if (!(*coord))
	{
		terminate(ERR_FD);
	}

	return (result);
}