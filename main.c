#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char 	*filename;
	int		fd;

	filename = "file.txt";
	fd = open(filename, O_RDWR);
	if (fd < 0)
		printf("Error");
	else
	{
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
		printf("String: %s\n", get_next_line(fd));
	}
	close(fd);
	return (0);
}
