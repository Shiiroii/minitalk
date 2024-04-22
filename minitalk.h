/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:52:25 by lionelulm         #+#    #+#             */
/*   Updated: 2024/04/22 10:02:26 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

int		ft_print_pid(int pid);
int		ft_checkerclient(int argc, char **argv);
void	ft_checkerserv(int sig);
void	ft_usechecker(void);

#endif
