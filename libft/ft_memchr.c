/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:02:51 by liulm             #+#    #+#             */
/*   Updated: 2024/10/18 13:18:34 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_str;
	unsigned char	chr;
	size_t			len;

	temp_str = (unsigned char *)s;
	chr = (unsigned char)c;
	len = 0;
	while (len < n)
	{
		if (temp_str[len] == chr)
			return (temp_str + len);
		len++;
	}
	return (NULL);
}
