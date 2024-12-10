/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:03:59 by liulm             #+#    #+#             */
/*   Updated: 2024/10/23 17:43:39 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				len;
	unsigned char		*tempdest;
	const unsigned char	*tempsrc;

	len = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	if (tempdest < tempsrc)
		return (ft_memcpy(dest, src, n));
	else
	{
		len = n;
		while (len > 0)
		{
			tempdest[len - 1] = tempsrc[len - 1];
			len--;
		}
	}
	return (dest);
}
