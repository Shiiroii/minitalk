/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:57:07 by lionelulm         #+#    #+#             */
/*   Updated: 2024/04/09 16:41:31 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_checker(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		handle_errors("Wrong number of arguments");
	while (argv[1][i])
		if (ft_isdigit(argv[1][i++]) == 0)
			handle_errors("Invalid PID");
	if (*argv[2] == 0)
		handle_errors("Empty message");
}

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
				kill(srv_pid, SIGURS1);
			else
				kill(srv_pid, SIGURS2);
			usleep(50);
			car <<= 1;
		}
		message++;
	}
}
