/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:33:56 by liulm             #+#    #+#             */
/*   Updated: 2024/10/15 14:43:07 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	size;
	char	*temp;

	size = 0;
	temp = s;
	while (size < n)
	{
		*temp = c;
		temp++;
		size++;
	}
	return (s);
}
