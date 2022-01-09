# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jscheuma <jscheuma@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 11:54:40 by jscheuma          #+#    #+#              #
#    Updated: 2022/01/05 20:36:53 by jscheuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SERVER = server
SERVER_SRCS = src/server.c
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)

CLIENT = client
CLIENT_SRCS = src/client.c
CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)

SRCS = 	src/ft_putstr_fd.c	\
		src/ft_itoa.c		\
		src/ft_putnbr_fd.c	\
		src/ft_atoi.c	
OBJS = $(SRCS:%.c=%.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(CLIENT)

clean:
	rm -f *.o *.out
	rm -f src/*.o*

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
