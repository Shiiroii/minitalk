# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:27:21 by lulm              #+#    #+#              #
#    Updated: 2024/04/25 18:13:46 by lionelulm        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

LIBFT = libft/libft.a

SERVER = server
CLIENT = client

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -fr

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER) $(LIBFT)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT) $(LIBFT)

$(LIBFT):
		$(MAKE) -C ./libft

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:	clean
	rm -f $(SERVER) $(CLIENT)

re:		fclean all

.PHONY: all clean fclean re
