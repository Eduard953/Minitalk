/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:58:26 by jscheuma          #+#    #+#             */
/*   Updated: 2021/05/21 09:58:26 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}
