/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:58:00 by liulm             #+#    #+#             */
/*   Updated: 2024/11/04 16:06:52 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (ft_putstr("(null)"));
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
