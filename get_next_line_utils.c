/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:09:32 by aantonie          #+#    #+#             */
/*   Updated: 2024/02/27 04:26:19 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @note cast becasue str is type void* and we need type char*
 */
void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (i < n)
	{
		*(char *)(str + 1) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= 2147483647 || size >= 2147483647)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
