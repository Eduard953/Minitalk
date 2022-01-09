/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jscheuma <jscheuma@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:50:43 by jscheuma          #+#    #+#             */
/*   Updated: 2022/01/05 12:38:19 by jscheuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
size_t	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif