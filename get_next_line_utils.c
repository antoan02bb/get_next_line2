/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:09:32 by aantonie          #+#    #+#             */
/*   Updated: 2024/03/08 18:32:31 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bzero, calloc, strlen, strchr, strjoin
#include "get_next_line.h"

/**
 * @brief 1. Create a new string with the size of both strings
 * @note  2. strlen() does not include terminating 0
 * @note  3. After concatenating the 2 strings I must initialize
 * the last index to 0 to properly null terminate the new string
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (s1 && s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != 0)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= 2147483647 || size >= 2147483647)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/**
 * @param 1. *str - a pointer to the located character
 * @note  2. int c - the ascii number of the char the function is looking for
 */
char	*ft_strchr(char *s, int c)
{
	char	searched_char;
	char	*str;

	str = (char *)s;
	searched_char = (char)c;
	while (*str != searched_char && *str != '\0')
		str++;
	if (*str == searched_char)
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
