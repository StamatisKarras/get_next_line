#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

//Library Calls:

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

//Function Declerations:

char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*file_read(int fd, char *storage);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *storage);
char	*update_storage(char *storage);

//Defines

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#endif
