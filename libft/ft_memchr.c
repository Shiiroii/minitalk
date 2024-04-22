/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:26:49 by lulm              #+#    #+#             */
/*   Updated: 2023/11/18 03:02:37 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scan;
	size_t			i;

	scan = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (scan[i] == (unsigned char)c)
		{
			return (scan + i);
		}
		i++;
	}
	return (NULL);
}
