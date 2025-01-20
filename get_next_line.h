#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Library Calls:

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

//Defines:

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

//Struct:

typedef	struct s_buffer {
	int		fd;
	int		eof;
	size_t	flushed_bytes;
	size_t	unflushed_bytes;
	char	memory[BUFFER_SIZE];
}	t_buffer;

//Function Declerations:

char	*get_next_line(int fd);
void	*ft_memmove(void *dest_str, const void *src_str, size_t n);
char	*ft_strjoin(char *s1, char *s2);
static void	read_to_buff(t_buffer *buffer);
static	size_t	next_index(t_buffer *buffer);
static	char	*flush_and_combine(t_buffer *buffer, size_t to_flush, char *line);
size_t	ft_strlen(const char *s);

#endif
