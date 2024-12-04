/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:24:30 by skarras           #+#    #+#             */
/*   Updated: 2024/12/04 12:47:22 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Library Calls:

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

//Function Declerations:

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*file_read(int fd, char *storage);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *storage);
char	*update_storage(char *storage);

//Defines:

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#endif
