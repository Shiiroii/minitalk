/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:39:49 by lionelulm         #+#    #+#             */
/*   Updated: 2024/10/18 11:02:18 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			len;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	len = 0;
	while (len < n)
	{
		if (temp_s1[len] != temp_s2[len])
			return (temp_s1[len] - temp_s2[len]);
		len++;
	}
	return (0);
}
