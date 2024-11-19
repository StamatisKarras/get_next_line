#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static size_t	BUFFER_SIZE;
	static size_t	i;
	size_t			size;
	size_t			index;
	char			*buffer;
	char			*arr;

	size = 0;
	BUFFER_SIZE = 1000;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	read(fd, buffer, sizeof(buffer));
	if (buffer[i] == '\n')
		i += 2;
	size += find_next(&buffer[i]);
	arr = (char *) malloc((size + 1) * sizeof(char));
	if (!arr)
	{
		free(arr);
		return (NULL);
	}
	while (index < size)
		arr[index++] = buffer[i++];
	arr[index] = '\0';
	return (arr);
}
