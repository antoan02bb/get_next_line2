/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:47:51 by aantonie          #+#    #+#             */
/*   Updated: 2024/03/06 20:11:03 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	// free(buffer);
	return (temp);
}

/**
 * @brief 1. extracts the current line from the buffer
 * @brief 2. stops when it encounters an '\0' or '\n'
 * @brief 3. allocates memory for the esxtracted line
 * @brief 4. returns the exracted line
 * @note - ! The extracted line 
 * @return pointer to the allocated memory containing the extracted line
 * @brief 5. Handle eol character - '\0': 
 * - line[i++] = '\n' means we go to the next line
 */
char	*ft_extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

/**
 * @brief 1. skips the current line
 * @brief 2. extracts the next line from the buffer
 * @brief 3. stops at the end of the buffer or the next '\n'
 * @brief 4. allocates memory for the extracted line
 * @brief 5. frees the memory of the current buffer
 * @return pointer to the allocated memory containing the extracted next line
 */
char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i] != '\0')
	{
		new_line[j] = buffer[i];
		j++;
		i++;
	}
	free(buffer);
	return (new_line);
}

/**
 * @note 1. ft_calloc(1, 1)
 - effectively creates an empty string.
 - allocates memory for a single character and initializes it to '\0'
 - call is used to allocate memory for an empty string.
 * @brief 4. create a buffer and allocate memory for it( +1 is for '\0')
 * @brief 5. if no bytes are read -> free the buffer
 * @brief 6. read() reaturns -1 if an error occurs while reading the file
 */
static char	*read_from_file(int fd, char *file_content)
{
	int		byte_read;
	char	buffer[BUFFER_SIZE + 1];

	// if (!file_content)
	// 	file_content = ft_calloc(1, 1);
	// buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	ft_bzero(&buffer, BUFFER_SIZE + 1);
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		file_content = ft_free(file_content, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (file_content);
}

/**
 * @brief 1. creates a buffer, that stores the whole text in the file
 * @brief 2. the content of the string that buffer points to is what changes.
 */
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_from_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	current_line = ft_extract_line(buffer);
	buffer = ft_next_line(buffer);
	return (current_line);
}
