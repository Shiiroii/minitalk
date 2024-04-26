/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:20:35 by lulm              #+#    #+#             */
/*   Updated: 2024/01/24 10:27:36 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	if (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = nbr_len(nb);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (i);
}

int	ft_putnbr_unsdec(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_putnbr_unsdec(nb / 10);
		i += ft_putnbr_unsdec(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}
