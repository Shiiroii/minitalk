/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:57:04 by lionelulm         #+#    #+#             */
/*   Updated: 2024/04/22 10:02:00 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_checkerserv(int sig)
{
	static int				i;
	static unsigned char	statcar;
	unsigned char			car;

	i = 0;
	statcar = 0;
	car = (sig == SIGUSR1);
	statcar |= (car << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(statcar, 1);
		statcar = 0;
		i = 0;
	}
}

void	ft_usechecker(void)
{
	struct sigaction	check;

	check.sa_handler = &ft_checkerserv;
	check.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &check, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &check, NULL) == -1)
		exit(1);
}

int	main(void)
{
	ft_printf("Server's PID: %d\n", getpid());
	ft_usechecker();
	while (1)
		pause();
	return (0);
}


