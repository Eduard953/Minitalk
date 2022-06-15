/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:30:03 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/12 13:57:02 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_sig(int pid, char c, int shift)
{
	if ((c >> shift) & 0x1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	return (shift + 1);
}

void	choose_bit(int pid, char *str)
{
	static int	i;
	static int	j;
	static int	s_pid;
	static char	*s_str;

	if (str)
	{
		s_pid = pid;
		s_str = str;
		i = 0;
		j = 0;
	}
	if (j == 7)
	{
		j = 0;
		i++;
	}
	if (s_str[i])
	{
		j = send_sig(s_pid, s_str[i], j);
		usleep(1000);
	}
	else
		exit (0);
}

void	handle(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR1 && (context || !context) && siginfo)
		choose_bit(0, NULL);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sgl;

	sgl.sa_flags = SA_SIGINFO;
	sgl.sa_sigaction = handle;
	sigaction(SIGUSR1, &sgl, NULL);
	if (argc != 3)
	{
		write(1, "error", 5);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	choose_bit(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
