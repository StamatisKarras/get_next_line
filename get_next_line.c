#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	char			*line;
	ssize_t			new_line_index;

	line = 	NULL;
	/*#1 If both of these Condisions are true then our array is empty
	#2 This is a loop that we use in order to keep putting thing in to line until \n or eof*/
	if (buffer.unflushed_bytes == 0 && buffer.flushed_bytes == 0) //#1
	{
		buffer.fd = fd;
		read_to_buff(&buffer);
	}
	while(1)
	{
		new_line_index = next_index(&buffer);
		if (new_line_index >= 0) // If next index is not -1 (which means error) then we have something to flush
			return (flush_and_combine(&buffer, new_line_index + 1, line)); // +1 Because we also need the \n
		if (buffer.eof == 1 && buffer.unflushed_bytes > 0)
			return (flush_and_combine(&buffer, buffer.unflushed_bytes, line));
		if (buffer.eof == 1 && buffer.unflushed_bytes == 0)
			return(line);
		line = flush_and_combine(&buffer, buffer.unflushed_bytes, line);// #2
		read_to_buff(&buffer); // #2
	}
}
/*This function is used to read BUFFER_SIZE in to buffer.memory
#1: We use this check to make sure that in the case the file we read is empty or if there was an error and read didn't
read anything the function stops and NULL is returned from get_next_line
#2: If bytes_read <  BUFFER_SIZE that means we have reached eof.*/
static void	read_to_buff(t_buffer *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(buffer->fd, buffer->memory, BUFFER_SIZE);
	if (bytes_read <= 0) // #1
	{
		buffer->eof = 1; // The eof(end of file) variable is set to 1 in order to indicate we have reached eof.
		buffer->unflushed_bytes = 0; // This is set to 0 because we have nothing to flush.
		buffer->flushed_bytes = BUFFER_SIZE; // Remember to explain why we do this later.
		return ;
	}
	buffer->unflushed_bytes = bytes_read; // We put bytes read in to unflushed bytes in order to indicate the amouint of bytes thnat we need to flush.
	buffer->flushed_bytes = 0; // If this function is called that means our array is empty and there is nothing that has been flushed.
	if (bytes_read < BUFFER_SIZE && buffer->fd != STDIN_FILENO) // #2
		buffer->eof = 1;
}
/*This function is used to find the next \n character in our array*/
static	size_t	next_index(t_buffer *buffer)
{
	size_t	i;
	size_t	offset;

	i = 0;
	offset = buffer->flushed_bytes; // Flushed bytes is used here as an ofset so that we don't keep returning the same line.
	while(i < buffer->unflushed_bytes)
	{
		if (buffer->memory[offset + i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
/*#1 If buffer->unflushed_bytes is == 0 then that mean there is nothing to flush, same with to_flush == 0;
#2 We need to make sure that to_flush is the same as unflushed_bytes,
if they aren't the same that means eof does not have a \n and so we need to make to_flush == unflushed_bytes*/
static	char	*flush_and_combine(t_buffer *buffer, size_t to_flush, char *line)
{
	size_t	offset;
	char	*temp;

	if (!buffer || buffer->unflushed_bytes == 0 || to_flush == 0) //#1
		return (NULL);
	if (to_flush > buffer->unflushed_bytes) //#2
		to_flush = buffer->unflushed_bytes;
	temp = (char *) malloc((to_flush + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	offset = buffer->flushed_bytes;
	ft_memmove(temp, buffer->memory + offset, to_flush);
	temp[to_flush] = '\0';
	buffer->unflushed_bytes -= to_flush;
	buffer->flushed_bytes += to_flush;
	line = ft_strjoin(line, temp);
	return (line);
}
