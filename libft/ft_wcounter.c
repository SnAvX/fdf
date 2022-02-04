#include "libft.h"

int		ft_wcounter(char *s, char c)
{
	size_t i;
	size_t wordcounter;

	i = 0;
	wordcounter = 0;
	while (s[i])
	{
		if (s[i] != c)
			wordcounter++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (wordcounter);
}