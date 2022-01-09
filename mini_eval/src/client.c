/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:52:37 by jscheuma          #+#    #+#             */
/*   Updated: 2022/01/06 09:46:00 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send(int s_pid, char *message)
{
	int	i;
	int	bit;

	(void)s_pid;
	i = 0;
	while (message[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((message[i] >> bit) & 1)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			bit--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	s_pid;

	(void)argv;
	if (argc != 3)
	{
		ft_putstr_fd("ERROR: You need exatly 2 Arguments. (PID, MESSAGE)\n", 1);
		exit(1);
	}
	s_pid = ft_atoi(argv[1]);
	send(s_pid, argv[2]);
	return (0);
}
