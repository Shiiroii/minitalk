/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:59:43 by liulm             #+#    #+#             */
/*   Updated: 2024/10/22 12:47:07 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*end;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	end = (char *)malloc(sizeof(char) * (len + 1));
	if (!end)
		return (NULL);
	while (i < len && s[i + start])
	{
		end[i] = s[i + start];
		i++;
	}
	end[i] = '\0';
	return (end);
}
