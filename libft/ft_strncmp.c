/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:41 by lulm              #+#    #+#             */
/*   Updated: 2023/11/20 15:40:42 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	chars1;
	unsigned char	chars2;
	size_t			i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		chars1 = (unsigned char)s1[i];
		chars2 = (unsigned char)s2[i];
		if (chars1 != chars2)
		{
			return (chars1 - chars2);
		}
		i++;
	}
	return (0);
}
