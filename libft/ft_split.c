/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:14:16 by lulm              #+#    #+#             */
/*   Updated: 2023/12/07 08:25:36 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cpy_word(char *str, char c)
{
	int		i;
	int		len;
	char	*array;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (array == NULL)
		return (NULL);
	ft_strlcpy(array, str, i + 1);
	len = ft_strlen(array);
	while (len > 0 && (array[len - 1] == '\n' || array[len - 1] == '\t'))
		array[--len] = '\0';
	return (array);
}

int	word_number(char *str, char c)
{
	int	i;
	int	nbr;
	int	word;

	i = 0;
	nbr = 0;
	word = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] != '\0' && str[i] == c)
				i++;
			if (str[i] != '\0')
				nbr++;
		}
		else
			i++;
		if (str[i] != '\0' && str[i] != c)
			word = 1;
	}
	return (word + nbr);
}

char	**free_split(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		str_count;
	char	**array;

	i = 0;
	if (s == NULL)
		return (NULL);
	str_count = word_number((char *)s, c);
	array = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (array == NULL)
		return (NULL);
	while (i < str_count)
	{
		while (*s == c)
			s++;
		array[i] = cpy_word((char *)s, c);
		if (array[i] == NULL)
			return (free_split(array));
		s += ft_strlen(array[i]);
		i++;
	}
	while (*s == c)
		s++;
	array[i] = NULL;
	return (array);
}
