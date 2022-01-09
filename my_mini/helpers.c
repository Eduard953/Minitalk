/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:51:57 by ebeiline          #+#    #+#             */
/*   Updated: 2021/10/11 16:53:46 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_sign(char c)
{
	if (c == '+')
		return (1);
	else
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	j = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		j = ft_sign(nptr[i]);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb * j);
}

static int	ft_num_digits(long long n)
{
	int		i;

	i = 0;
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_power(int i)
{
	int		div;

	div = 1;
	while (i > 0)
	{
		div = div * 10;
		i--;
	}
	return (div);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*a;
	int			div;
	long long	numb;

	numb = n;
	i = ft_num_digits(numb);
	a = (char *)malloc(sizeof(char) * (i + 2));
	if (!a)
		return (NULL);
	div = ft_power(i - 1);
	i = 0;
	if (numb < 0)
	{
		a[i++] = '-';
		numb = numb * (-1);
	}
	while (div > 0)
	{
		a[i] = ((numb / div) % 10 + '0');
		i++;
		div /= 10;
	}
	a[i] = '\0';
	return (a);
}
