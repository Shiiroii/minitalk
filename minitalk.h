/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:52:25 by lionelulm         #+#    #+#             */
/*   Updated: 2024/04/22 09:13:57 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

int		ft_print_pid(int pid);
int		ft_checkerclient(int argc, char **argv);
int		ft_checkerserv(int sig);
void	ft_usechecker(void);

#endif
