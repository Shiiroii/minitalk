/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:49:32 by liulm             #+#    #+#             */
/*   Updated: 2024/10/21 16:03:37 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[len_s1])
	{
		str[len_s1] = s1[len_s1];
		len_s1++;
	}
	while (s2[len_s2])
	{
		str[len_s1] = s2[len_s2];
		len_s1++;
		len_s2++;
	}
	str[len_s1] = '\0';
	return (str);
}
