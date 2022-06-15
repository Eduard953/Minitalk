# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:35:55 by ebeiline          #+#    #+#              #
#    Updated: 2022/01/11 17:14:55 by ebeiline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= client
SNAME	= server

SRV		= server.c
CLI		= client.c
HLP		= helpers.c ft_strlen.c

RM			= rm -f
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror

all : $(NAME) $(SNAME)

$(NAME) : $(CLI) $(HLP)
	$(CC) $(CFLAGS) $(CLI) $(HLP) -o client

$(SNAME): $(SRV) $(HLP)
	$(CC) $(CFLAGS) $(SRV) $(HLP) -o server

fclean : 
	$(RM) server client

clean : 
	$(RM) server client

re : fclean all

bonus : fclean all