/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:52:35 by jscheuma          #+#    #+#             */
/*   Updated: 2022/01/06 09:57:34 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	str;
	static int	c_pid;

	(void)context;
	(void)info;
	if (c_pid != info->si_pid)
	{
		bit = 0;
		c_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		str = (str << 1) | 1;
	else if (sig == SIGUSR2)
		str = (str << 1);
	bit++;
	if (bit == 8)
	{
		write(1, &str, 1);
		bit = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig_action;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("ERROR: No Arguments needed!\n", 1);
		exit(1);
	}
	sig_action.sa_handler = 0;
	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = sig_handler;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (1)
		pause();
	return (0);
}
