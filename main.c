#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char 	*filename;
	int		fd;
	char	*str;

	filename = "file.txt";
	fd = open(filename, O_RDWR);
	if (fd < 0)
		printf("Error");
	else
	{
		str = get_next_line(fd);
		while (str)
		{
			printf("%s", str);
			str = get_next_line(fd);
		}
	}
	close(fd);
	return (0);
}
