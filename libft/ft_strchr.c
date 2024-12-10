/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:17:03 by liulm             #+#    #+#             */
/*   Updated: 2024/10/23 17:46:28 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}
