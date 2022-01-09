/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:33:22 by jscheuma          #+#    #+#             */
/*   Updated: 2021/05/14 16:33:22 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

size_t	ft_atoi(const char *str)
{
	char	*s;
	size_t	mult;
	size_t	num;

	mult = 1;
	s = (char *)str;
	num = 0;
	if (!(*str))
		return (0);
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\f' || *s == '\r' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			mult = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (num * mult);
}
