#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*rtn;

	rtn = (char *)malloc(size + 1);
	if (rtn != (char *)NULL)
		ft_bzero((void *)rtn, size + 1);
	return (rtn);
}
