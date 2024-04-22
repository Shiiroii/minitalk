/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:10:40 by lionelulm         #+#    #+#             */
/*   Updated: 2023/12/07 09:20:20 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	test;

	test = nmemb * size;
	if (nmemb && size && (test / nmemb != size))
		return (NULL);
	ptr = malloc(test);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (test));
	return (ptr);
}
