/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:21:50 by liulm             #+#    #+#             */
/*   Updated: 2025/01/29 16:23:31 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server_checker(int sig, siginfo_t *info, void *signal)
{
	static int				i = 0;
	static unsigned char	statcar = 0;

	(void)signal;
	if (sig == SIGUSR1)
		statcar = (statcar << 1) | 0b00000001;
	else if (sig == SIGUSR2)
		statcar = statcar << 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", statcar);
		i = 0;
		statcar = 0;
	}
	if (info && info->si_pid)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	handler;

	ft_printf("Server's PID: %d\n", getpid());
	handler.sa_sigaction = ft_server_checker;
	handler.sa_flags = SA_SIGINFO;
	sigemptyset(&handler.sa_mask);
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	while (1)
		pause();
	return (0);
}
