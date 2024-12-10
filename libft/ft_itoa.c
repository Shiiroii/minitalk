/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:16:54 by liulm             #+#    #+#             */
/*   Updated: 2024/10/30 21:49:48 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_int(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	nbr;
	char		*str;

	nbr = n;
	len = len_of_int(nbr);
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
