/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:35 by liulm             #+#    #+#             */
/*   Updated: 2025/01/29 16:23:46 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		ft_printf_pid(int pid);
int		ft_client_checker(int argc, char **argv);
void	ft_server_checker(int sig, siginfo_t *info, void *signal);

bool	g_finished = false;

#endif
