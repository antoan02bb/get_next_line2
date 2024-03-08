/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:47:51 by aantonie          #+#    #+#             */
/*   Updated: 2024/03/08 16:35:49 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_from_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

static char	*read_from_file(int fd, char *file_content)
{
	int		byte_read;
	char	buffer[BUFFER_SIZE + 1];

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

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	// free(buffer);
	return (temp);
}
