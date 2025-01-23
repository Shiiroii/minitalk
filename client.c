/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:51:44 by liulm             #+#    #+#             */
/*   Updated: 2025/01/23 16:23:47 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	is_it_done(int sig)
{
	(void)sig;
	finished = true;
}

void	ft_transfer_message(pid_t srv_pid, char *message)
{
	unsigned char		car;
	int					bits;
	struct sigaction	check;
	bool	finished = false;

	check.sa_handler = is_it_done;
	check.sa_flags = 0;
	sigemptyset(&check.sa_mask);
	sigaction(SIGUSR1,&check, NULL);
	while (*message)
	{
		car = *message;
		bits = 8;
		while (bits--)
		{
			finished = false;
			if (car & (1 << 7))
				kill(srv_pid, SIGUSR1);
			else
				kill(srv_pid, SIGUSR2);
			while (!finished)
				pause();
			car <<= 1;
		}
		message++;
	}
}

int	ft_client_checker(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments (Usage: ./client [PID] [Text])\n");
		return (1);
	}
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i++]) == 0)
		{
			ft_printf("Invalid PID\n");
			return (1);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Empty message\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (ft_client_checker(argc, argv) != 0)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid == 0 && argv[1][0] != '0')
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	ft_transfer_message(pid, argv[2]);
	ft_transfer_message(pid, "\0");
	return (0);
}
