/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:26 by liulm             #+#    #+#             */
/*   Updated: 2024/11/04 15:00:49 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_len(unsigned long long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

static void	to_hexa(unsigned long long nb)
{
	if (nb >= 16)
	{
		to_hexa(nb / 16);
		to_hexa(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar((nb - 10) + 'a');
	}
}

int	ft_hexvoid(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = write(1, "(nil)", 5);
	else
	{
		i = i + write(1, "0x", 2);
		to_hexa(nb);
		i = i + hexa_len(nb);
	}
	return (i);
}

int	ft_lowercase_hexa(unsigned int nb)
{
	int	result;

	result = 0;
	if (nb >= 16)
		result += ft_lowercase_hexa(nb / 16);
	if (nb % 16 < 10)
		result += ft_putchar((nb % 16) + 48);
	else
		result += ft_putchar((nb % 16) + 87);
	return (result);
}

int	ft_uppercase_hexa(unsigned int nb)
{
	int	result;

	result = 0;
	if (nb >= 16)
		result += ft_uppercase_hexa(nb / 16);
	if (nb % 16 < 10)
		result += ft_putchar((nb % 16) + 48);
	else
		result += ft_putchar((nb % 16) + 55);
	return (result);
}
