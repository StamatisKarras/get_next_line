/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:20:30 by skarras           #+#    #+#             */
/*   Updated: 2024/12/04 12:12:09 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_storage(char *storage)
{
	char	*new_storage;
	size_t	i;
	size_t	j;

	i = 0;
	while (storage[i] != '\n' && storage[i]) // incrimenting to end of first line in order to use in malloc
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = (char *) malloc((ft_strlen(storage) - i + 1) * sizeof(char)); // Because we don't want to copy the first line we allocate space for ft_strlen(storage) - firstline in storage.
	if (!new_storage)
		return (NULL);
	i++; // If we don't ++ here we would be pointing to the new line character.
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] != '\n' && storage[i]) // Counting up to the first line
		i++;
	line = (char *) malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] != '\n' && storage[i]) // Copying the first line
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n') // IF there is a newline character we want to include it
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*file_read(int fd, char *storage)
{
	ssize_t	bytes_read;
	char	*buff;
	int		i;

	i = 0;
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read != 0 && i < BUFFER_SIZE) // This check is important to make sure that in consecutive calls we don't overwrite what is in buffer_storage.
	{
		bytes_read = read(fd, buff, 1); // Reads 1 byte from the file (fd) and puts it in buff.
		if (bytes_read == -1) // If bytes_read is == to 1 then that means there was an error reading the file.
		{
			free(buff);
			return(NULL);
		}
		buff[bytes_read] = '\0';
		storage = ft_strjoin(storage, buff); // Simply sending the storage and buff to ft_strjoin which adds the string pointed to by buff at the end of storage.
		i++;
	}
	free(buff);
	return (storage);
}

char *get_next_line(int fd)
{
	static	char	*buff_storage;
	char			*line;

	if(fd < 0 || BUFFER_SIZE < 1) // We use this check here because if fd(file descriptor) is < 0 then that mean there was no file read.
								// The BUFFER_SIZE check is there to make sure that we can atleast read 1 byte at a time.
		return (NULL);
	buff_storage = file_read(fd, buff_storage); // We send the Buffer storage and the fd to the file_read function in order
												// to get the text writen in the file pointed to by fd and put it in buffer_storage.
	if (!buff_storage)
		return (NULL);
	line = extract_line(buff_storage); // Sending buff_storage to extract_line in order to extract only the first line from buff_storage.
	buff_storage = update_storage(buff_storage);// After everything is done we send the buff_storage to this function in order to remove the current line we just extracted from the buff_storage.
	return (line);
}
