/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:09:25 by aantonie          #+#    #+#             */
/*   Updated: 2024/03/06 20:00:00 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);

// utils
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *str, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlen(char *s);

#endif