#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char 	*filename;
	char 	*filename2;
	char 	*filename3;
	int		fd;
	int		fd2;
	int		fd3;

	filename = "file.txt";
	filename2 = "file2.txt";
	filename3 = "file3.txt";
	fd = open(filename, O_RDWR);
	fd2 = open(filename2, O_RDONLY);
	fd3 = open(filename3, O_RDONLY);
	if (fd < 0 || fd2 < 0 || fd3 < 0)
		printf("Error");
	else
	{
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd3));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd3));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd3));
	}
	/*else
	{
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd2));
	}*/
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
