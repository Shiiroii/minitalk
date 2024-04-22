/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 07:47:56 by lulm              #+#    #+#             */
/*   Updated: 2024/02/01 10:51:47 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_plength(unsigned long long int i)
{
	int	j;

	j = 0;
	if (i == 0)
		j++;
	while (i != 0)
	{
		i = i / 16;
		j++;
	}
	return (j);
}

void	ft_hex(unsigned long long n)
{
	if (n >= 16)
	{
		ft_hex(n / 16);
		ft_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar((n - 10) + 'a');
	}
}

int	ft_hexvoid(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		i = write(1, "(nil)", 5);
	}
	else
	{
		i = i + write(1, "0x", 2);
		ft_hex(ptr);
		i = i + ft_plength(ptr);
	}
	return (i);
}
