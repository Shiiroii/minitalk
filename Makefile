# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:27:21 by lulm              #+#    #+#              #
#    Updated: 2024/04/26 11:20:11 by lulm             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

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

$(SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft

 $(PRINTF):
		$(MAKE) -C ./ft_printf

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean

fclean:	clean
	rm -f $(SERVER) $(CLIENT)

re:		fclean all

.PHONY: all clean fclean re
