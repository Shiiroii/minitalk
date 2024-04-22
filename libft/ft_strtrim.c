/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:00:43 by lionelulm         #+#    #+#             */
/*   Updated: 2023/11/17 11:39:35 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	to_find(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

unsigned int	startofstr(char *s1, char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (to_find(s1[i], set) == 1)
		{
			break ;
		}
		i++;
	}
	return (i);
}

unsigned int	endofstr(char *s1, char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (to_find(s1[i], set) == 1)
		{
			break ;
		}
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*setstr;
	int		start;
	int		end;

	if (!s1 || !set)
	{
		return (NULL);
	}
	str = (char *)s1;
	setstr = (char *)set;
	start = startofstr(str, setstr);
	end = endofstr(str, setstr) - start;
	return (ft_substr(str, start, end));
}
