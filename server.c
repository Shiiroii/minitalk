/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:57:04 by lionelulm         #+#    #+#             */
/*   Updated: 2024/04/26 11:05:52 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_checkerserv(int sig)
{
	static int				i = 0;
	static unsigned char	statcar = 0;

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
}

int	main(void)
{
	struct sigaction	handler;

	ft_printf("Server's PID: %d\n", getpid());
	handler.sa_handler = &ft_checkerserv;
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	while (1)
		pause();
	return (0);
}
