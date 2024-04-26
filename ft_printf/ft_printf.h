/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 07:29:30 by lulm              #+#    #+#             */
/*   Updated: 2024/04/25 18:17:36 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		nbr_len(int nb);
int		nbr_len_di(long int nb);
int		ft_putcharprintf_fd(char c, int fd);
int		ft_putnbr(int nb);
int		ft_putnbr_di(long int nb);
int		ft_putnbr_unsdec(unsigned int nb);
int		ft_plength(unsigned long long int i);
int		ft_hexvoid(unsigned long long int i);
int		ft_lowhexa(unsigned int nb);
int		ft_uphexa(unsigned int nb);
int		ft_printf(const char *str, ...);

#endif
