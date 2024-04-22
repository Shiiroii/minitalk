/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:46 by lulm              #+#    #+#             */
/*   Updated: 2023/11/23 15:23:20 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;
	char	*str;

	i = ft_strlen(s);
	chr = (char) c;
	str = (char *) s;
	while (i >= 0)
	{
		if (*(s + i) == chr)
			return (str + i);
		i--;
	}
	return (NULL);
}
