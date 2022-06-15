/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:58:27 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/11 16:01:37 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <signal.h>

typedef struct msg
{
	char		chr;
	size_t		size;
	int			shift;
}				t_msg;

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

#endif