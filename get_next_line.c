/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:10:36 by aantonie          #+#    #+#             */
/*   Updated: 2024/02/27 11:28:58 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// printf("ft_calloc#[%d]---", count++); - was part of code
// static int	count = 1;

/**
 * @brief reads the next line from a file descriptor (fd)
 * @brief reads data from a file and append it to a partial content
 * @note when testing remove free(buffer), to see if memory leaks occur
 */
static char	*read_from_file(int fd)
{
	int			bytes_read;
	char		*buffer;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

/**
 * @brief gets the next line from the file descriptor
 * @return a string, where the read characters are placed
 */
char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = read_from_file(fd);
	return (buffer);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*new_line;
// 	int		count;

// 	count = 0;
// 	fd = open("alphabet.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("We have an error opening the file");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		new_line = get_next_line(fd);
// 		if (new_line == NULL)
// 			break ;
// 		count++;
// 		printf("%s\n", new_line);
// 		free(new_line);
// 		new_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
