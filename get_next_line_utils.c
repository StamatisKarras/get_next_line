#include "get_next_line.h"

size_t	find_next(char *s)
{
	size_t	i;

	i = 0;
	while(s[i] != '\n' && s[i])
		i++;
	return (i);
}
