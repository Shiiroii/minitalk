/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:35 by liulm             #+#    #+#             */
/*   Updated: 2025/01/21 16:15:42 by liulm            ###   ########.fr       */
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

struct sigaction	check;
bool	finished = false;

#endif
