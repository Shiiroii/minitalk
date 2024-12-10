/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:35:53 by liulm             #+#    #+#             */
/*   Updated: 2024/10/23 17:53:02 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*temp_str;
	int		len;

	chr = (char)c;
	temp_str = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(s + len) == chr)
			return (temp_str + len);
		len--;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}
