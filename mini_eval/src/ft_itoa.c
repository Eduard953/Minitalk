/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:24:09 by jscheuma          #+#    #+#             */
/*   Updated: 2021/05/20 10:24:09 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	get_length(int tmp, int *dec, int *count)
{
	while (tmp > 9 || tmp < -9)
	{
		tmp /= 10;
		*dec *= 10;
		(*count)++;
	}
}

void	write_string(int n, int *dec, int *tmp, char *result)
{
	char	*max;

	max = "2147483648";
	if (n == -2147483648)
	{
		while (*max)
		{
			result[*tmp] = *max;
			max++;
			(*tmp)++;
		}
		return ;
	}
	while (*dec > 0)
	{
		result[*tmp] = ((n / *dec) % 10) + '0';
		*dec /= 10;
		(*tmp)++;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		tmp;
	int		dec;
	int		count;

	dec = 1;
	count = 0;
	get_length(n, &dec, &count);
	tmp = 0;
	if (n < 0)
	{
		result = malloc(sizeof(char) * (count + 3));
		result[tmp] = '-';
		n = n * -1;
		tmp++;
	}
	else
		result = malloc(sizeof(char) * (count + 2));
	write_string(n, &dec, &tmp, result);
	result[tmp] = '\0';
	return (result);
}
