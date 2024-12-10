/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:51:09 by liulm             #+#    #+#             */
/*   Updated: 2024/11/04 15:14:19 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_parsing(va_list arg, const char *ptr, int i)
{
	int	parser;

	parser = 0;
	if (ptr[i] == 'c')
		parser += ft_putchar_fd(va_arg(arg, int), 1);
	else if (ptr[i] == 's')
		parser += ft_putstr(va_arg(arg, char *));
	else if (ptr[i] == 'p')
		parser += ft_hexvoid(va_arg(arg, unsigned long long int));
	else if (ptr[i] == 'd' || ptr[i] == 'i')
		parser += ft_putnbr_d_i(va_arg(arg, int));
	else if (ptr[i] == 'u')
		parser += ft_putnbr_uns_dec(va_arg(arg, unsigned int));
	else if (ptr[i] == 'x')
		parser += ft_lowercase_hexa(va_arg(arg, unsigned int));
	else if (ptr[i] == 'X')
		parser += ft_uppercase_hexa(va_arg(arg, unsigned int));
	else if (ptr[i] == '%')
		parser += ft_putchar('%');
	return (parser);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		parsing;
	va_list	arg;

	i = 0;
	parsing = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			parsing += printf_parsing(arg, str, i++);
		}
		else
			parsing += ft_putchar(str[i++]);
	}
	va_end(arg);
	return (parsing);
}
