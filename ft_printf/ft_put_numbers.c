/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:49:56 by liulm             #+#    #+#             */
/*   Updated: 2024/11/04 15:09:32 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len_d_i(long int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_d_i(long int nb)
{
	int	len;

	len = nbr_len_d_i(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (len);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb > 9)
		{
			ft_putnbr_d_i(nb / 10);
		}
		ft_putchar(nb % 10 + '0');
	}
	return (len);
}

int	ft_putnbr_uns_dec(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_putnbr_uns_dec(nb / 10);
		i += ft_putnbr_uns_dec(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}
