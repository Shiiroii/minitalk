/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:49:14 by liulm             #+#    #+#             */
/*   Updated: 2024/10/30 21:50:15 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c)
{
	size_t	i;
	size_t	num;
	size_t	word;

	i = 0;
	num = 0;
	word = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i])
				num++;
		}
		else
			i++;
		if (s[i] && s[i] != c)
			word = 1;
	}
	return (word + num);
}

static char	*sep_words(char *s, char c)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s, i + 1);
	len = ft_strlen(temp);
	while (len > 0 && (temp[len - 1] == '\n' || temp[len - 1] == '\t'))
	{
		--len;
		temp[len] = '\0';
	}
	return (temp);
}

static char	**free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
	char	**array;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = count_words((char *)s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	while (i < word_count)
	{
		while (*s == c)
			s++;
		array[i] = sep_words((char *)s, c);
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
