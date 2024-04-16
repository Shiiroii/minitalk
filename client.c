/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:57:07 by lionelulm         #+#    #+#             */
/*   Updated: 2024/04/16 15:26:47 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_checker(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		ft_printf("Wrong number of arguments");
	while (argv[1][i])
		if (ft_isdigit(argv[1][i++]) == 0)
			ft_printf("Invalid PID");
	if (*argv[2] == 0)
		ft_printf("Empty message");
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
/*si jamais ya un probleme de timing, change la valeur a 50 ou plus haut*/
			usleep(25);
			car <<= 1;
		}
		message++;
	}
}

void	minitalk_client()
{

}
