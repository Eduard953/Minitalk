/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:29:55 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/11 17:29:39 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

void	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

static void	get_sig(int sig, siginfo_t *siginfo, void *context)
{
	if ((sig == SIGUSR1) && (context || !context))
		g_msg.chr = (g_msg.chr >> 1) + 0x40;
	else
		g_msg.chr = g_msg.chr >> 1;
	g_msg.size++;
	if (g_msg.size == 7)
	{
		write(1, &g_msg.chr, 1);
		g_msg.chr = 0;
		g_msg.size = 0;
	}
	//usleep(100);
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_msg.chr = 0;
	g_msg.size = 0;
	print_pid();
	sa.sa_sigaction = &get_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (1);
}
