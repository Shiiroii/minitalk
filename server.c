/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:21:50 by liulm             #+#    #+#             */
/*   Updated: 2024/12/10 12:36:54 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server_checker(int sig)
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
	handler.sa_handler = &ft_server_checker;
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	while (1)
		pause();
	return (0);
}
