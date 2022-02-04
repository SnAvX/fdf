#include "../include/struct.h"
#include "../include/fdf.h"
#include <stdlib.h>

void	push(t_coord **coords, t_coord *new)
{
	if (coords)
	{
		if (new)
			new->mem = *coords;
		*coords = new;
	}
}

t_coord *top(t_coord **coord)
{
    t_coord *save;

    save = NULL;
    if(coord && *coord)
    {
        save = *coord;
        *coord = (*coord)->mem;
    }
    return (save);
}