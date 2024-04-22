/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:08:52 by lulm              #+#    #+#             */
/*   Updated: 2023/11/23 15:09:44 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i + little_len <= len)
	{
		if ((ft_strncmp(big + i, little, little_len)) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
