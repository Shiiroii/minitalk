/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:04:16 by lulm              #+#    #+#             */
/*   Updated: 2023/11/18 16:24:18 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*pdest;
	const unsigned char	*psrc;

	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (pdest < psrc)
	{
		return (ft_memcpy(dest, src, n));
	}
	else
	{
		i = n;
		while (i > 0)
		{
			pdest[i - 1] = psrc[i - 1];
			i--;
		}
		return (dest);
	}
}
