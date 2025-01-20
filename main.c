#include "get_next_line.h"

int	main(void)
{
	size_t	fd;
	char	*line;

	fd = open ("file.txt", O_RDONLY);
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	close(fd);
	return (0);
}
