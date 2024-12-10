/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:52:14 by liulm             #+#    #+#             */
/*   Updated: 2024/11/04 15:09:11 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_hexvoid(unsigned long long nb);
int	ft_lowercase_hexa(unsigned int nb);
int	ft_uppercase_hexa(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr(char *str);
int	ft_putnbr_d_i(long int nb);
int	ft_putnbr_uns_dec(unsigned int nb);

#endif
