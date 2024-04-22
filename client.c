/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:57:07 by lionelulm         #+#    #+#             */
/*   Updated: 2024/04/22 09:12:20 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_transfer_message(pid_t srv_pid, char *message)
{
	unsigned char	car;
	int				bits;

	while (*message)
	{
		car = *message;
		bits = 8;
		while (bits--)
		{
			if (car & (1 << 7))
				kill(srv_pid, SIGUSR1);
			else
				kill(srv_pid, SIGUSR2);
/*si jamais ya un probleme de timing, change la valeur a 50 ou plus haut*/
			usleep(25);
			car <<= 1;
		}
		message++;
	}
}

int	ft_checkerclient(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong number of arguments");
		return (1);
	}
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i++]) == 0)
		{
			ft_printf("Invalid PID");
			return (1);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Empty message");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_checkerclient(argc, argv) != 0)
		return(1);
	pid_t	pid;

	pid = ft_atoi(argv[1]);
	if (pid == 0 && argv[1][0] != '0')
	{
		printf("Invalid PID\n");
		exit(1);
	}
	ft_transfer_message(pid, argv[2]);
	return (0);
}
